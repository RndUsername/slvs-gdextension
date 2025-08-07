#include "point.h"
#include <godot_cpp/core/class_db.hpp>
#include "sketch.h"

using namespace godot;

void Point::_bind_methods() {
	ClassDB::bind_method(D_METHOD("update_position"), &Point::update_position);
}

Point::Point() {
}

Point::~Point() {
	// Add your cleanup here.
}

void Point::_enter_tree() {
	Node* parent = get_parent();

	if (parent == NULL) {
		UtilityFunctions::print("parent is null");
		return;
	}
	Sketch *sketch = Object::cast_to<Sketch>(this->get_parent());
	entity = Slvs_AddPoint2D(sketch->group, get_position().x, get_position().y, sketch->workplane);

	UtilityFunctions::print(
		"entity:", entity.group, "; ", 
		Slvs_GetParamValue(entity.param[0]), "; ",
		Slvs_GetParamValue(entity.param[1])
	);
	UtilityFunctions::print("pos: x:", get_position().x, " y:", get_position().y);
}

void Point::update_position() {
	Vector2 *updatedPos = new Vector2(
		Slvs_GetParamValue(entity.param[0]),
		Slvs_GetParamValue(entity.param[1])
	);
	set_position(*updatedPos);
}
