#ifndef LINE_H
#define LINE_H

#include <godot_cpp/classes/area2d.hpp>
#include "lib/slvs/slvs.h"
#include "point.h"

namespace godot {

	class Line : public Area2D {
		GDCLASS(Line, Area2D)

		private:
			Slvs_Entity entity;
			Point *pointA;
			Point *pointB;

		protected:
			static void _bind_methods();

		public:
			Line();
			~Line();
			void construct();

			void set_pointA(Point* p_pointA);
			Point *get_pointA();
			void set_pointB(Point *p_pointB);
			Point *get_pointB();
			void add_constraint_vertical();
	};
}

#endif