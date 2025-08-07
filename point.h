#ifndef POINT_H
#define POINT_H

#include <godot_cpp/classes/area2d.hpp>
#include "lib/slvs/slvs.h"

namespace godot {

	class Point : public Area2D {
		GDCLASS(Point, Area2D)

		protected:
			static void _bind_methods();

		public:
			Slvs_Entity entity;

			Point();
			~Point();

			void _enter_tree() override;
			void update_position();
	};

}

#endif