#pragma once

#include "TES3Defines.h"

#include "TES3Collections.h"
#include "TES3Item.h"

namespace TES3 {
	struct Misc : Item {
		Iterator<void> stolenList; // 0x30
		char * name; // 0x44
		Script * script; // 0x48
		char * model; // 0x4C
		char * icon; // 0x50
		float weight; // 0x54
		long value; // 0x58
		unsigned int flags; // 0x5C
	};
	static_assert(sizeof(Misc) == 0x60, "TES3::Misc failed size validation");
}
