#ifndef SKETCH_H
#define SKETCH_H

#include <godot_cpp/classes/static_body2d.hpp>
#include "lib/slvs/slvs.h"

namespace godot {

	class Sketch : public StaticBody2D {
		GDCLASS(Sketch, StaticBody2D)

		private:
			void solve();

		protected:
			static void _bind_methods();

		public:
			Sketch();
			~Sketch();

			Slvs_Entity workplane;
			Slvs_hGroup group;
	};

}

#endif