#include "line.h"
#include <godot_cpp/core/class_db.hpp>
#include "sketch.h"

using namespace godot;

void Line::_bind_methods() {
	ClassDB::bind_method(D_METHOD("construct"), &Line::construct);
	ClassDB::bind_method(D_METHOD("add_constraint_vertical"), &Line::add_constraint_vertical);

	ClassDB::bind_method(D_METHOD("get_pointA"), &Line::get_pointA);
	ClassDB::bind_method(D_METHOD("set_pointA", "p_pointA"), &Line::set_pointA);
	ADD_PROPERTY(
		PropertyInfo(Variant::OBJECT, "pointA", PROPERTY_HINT_RESOURCE_TYPE, "Point"),
		"set_pointA", "get_pointA"
	);

	ClassDB::bind_method(D_METHOD("get_pointB"), &Line::get_pointB);
	ClassDB::bind_method(D_METHOD("set_pointB", "p_pointB"), &Line::set_pointB);
	ADD_PROPERTY(
		PropertyInfo(Variant::OBJECT, "pointB", PROPERTY_HINT_RESOURCE_TYPE, "Point"),
		"set_pointB", "get_pointB"
	);
}

Line::Line() {
}

Line::~Line() {
	// Add your cleanup here.
}

void Line::construct() {
	Sketch* sketch = Object::cast_to<Sketch>(this->get_parent());

	entity = Slvs_AddLine2D(
		sketch->group, 
		pointA->entity,
		pointB->entity,
		sketch->workplane
	);
}

void godot::Line::set_pointA(Point* p_pointA) {
	pointA = p_pointA;
}

Point* Line::get_pointA() {
	return pointA;
}

void Line::set_pointB(Point* p_pointB) {
	pointB = p_pointB;
}

Point* Line::get_pointB() {
	return pointB;
}

void Line::add_constraint_vertical() {
	Sketch* sketch = Object::cast_to<Sketch>(this->get_parent());
	Slvs_Vertical(
		sketch->group,
		entity,
		sketch->workplane,
		SLVS_E_NONE
	);
}

