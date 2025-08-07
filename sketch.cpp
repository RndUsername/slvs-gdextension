#include "sketch.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void Sketch::_bind_methods() {
	ClassDB::bind_method(D_METHOD("solve"), &Sketch::solve);
}

Sketch::Sketch() {
	workplane = Slvs_AddBase2D(1);
	group = 1;
}

Sketch::~Sketch() {
	// Add your cleanup here.
}

void Sketch::solve() {
	Slvs_SolveSketch(group, nullptr);
}