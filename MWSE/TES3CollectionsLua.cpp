#include "TES3CollectionsLua.h"

#include "sol.hpp"
#include "LuaUtil.h"
#include "LuaManager.h"

#include "TES3Attachment.h"
#include "TES3Cell.h"
#include "TES3Dialogue.h"
#include "TES3DialogueInfo.h"
#include "TES3GlobalVariable.h"
#include "TES3Inventory.h"
#include "TES3Item.h"
#include "TES3Faction.h"
#include "TES3LeveledList.h"
#include "TES3MobileActor.h"
#include "TES3Quest.h"
#include "TES3Reference.h"
#include "TES3Region.h"
#include "TES3Spell.h"

#include "NIProperty.h"

namespace mwse {
	namespace lua {
		void bindTES3Collections() {
			// Iterator bindings.
			bindIterator<TES3::EquipmentStack>("TES3EquipmentStackIterator", "TES3EquipmentStackIteratorNode");
			bindIterator<TES3::Faction::ReactionNode>("TES3ReactionNodeIterator", "TES3ReactionNodeIteratorNode");
			bindIterator<TES3::ItemStack>("TES3ItemStackIterator", "TES3ItemStackIteratorNode");
			bindIterator<TES3::LeveledListNode>("TES3LeveledListNodeIterator", "TES3LeveledListNodeIteratorNode");
			bindIterator<TES3::RegionSound>("TES3RegionSoundIterator", "TES3RegionSoundIteratorNode");
			bindIterator<TES3::TravelDestination>("TES3TravelDestinationIterator", "TES3TravelDestinationIteratorNode");

			// Generic TES3::Object iterators. As above, but the result data will be reinterpreted at runtime.
			bindGenericObjectIterator<TES3::Dialogue>("TES3DialogueIterator", "TES3DialogueIteratorNode");
			bindGenericObjectIterator<TES3::DialogueInfo>("TES3DialogueInfoIterator", "TES3DialogueInfoIteratorNode");
			bindGenericObjectIterator<TES3::GlobalVariable>("TES3GlobalIterator", "TES3GlobalIteratorNode");
			bindGenericObjectIterator<TES3::MobileActor>("TES3MobileActorIterator", "TES3MobileActorIteratorNode");
			bindGenericObjectIterator<TES3::Quest>("TES3QuestIterator", "TES3QuestIteratorNode");
			bindGenericObjectIterator<TES3::Reference>("TES3ReferenceIterator", "TES3ReferenceIteratorNode");
			bindGenericObjectIterator<TES3::Region>("TES3RegionIterator", "TES3RegionIteratorNode");
			bindGenericObjectIterator<TES3::Spell>("TES3SpellIterator", "TES3SpellIteratorNode");

			// Generic TES3::Object STL collections.
			bindGenericObjectStlList<TES3::Cell>("TES3CellStlList", "TES3CellStlListNode");

			// Basic TArray bindings.
			bindTArray<TES3::ItemData>("TES3ItemDataTArray");

			// Bind some iterators.
			sol::state& state = LuaManager::getInstance().getState();
			state.new_usertype<TES3::LinkedList<TES3::Object>>("TES3ObjectLinkedList",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Meta functions.
				//

				sol::meta_function::index, [](TES3::LinkedList<TES3::Object>& self, int index)
			{
				TES3::Object* object = self.head;
				while (object && index > 1) {
					object = object->nextInCollection;
					index--;
				}
				return makeLuaObject(object);
			},
				sol::meta_function::length, [](TES3::LinkedList<TES3::Object>& self) { return self.size; }

			);
		}
	}
}
