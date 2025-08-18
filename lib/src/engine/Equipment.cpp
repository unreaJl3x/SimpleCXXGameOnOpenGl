#include "Equipment.h"

#define EQUIPMENTELEMENTS(i) vector<int_s> {                       \
EQUIPMENT_TYPES::FLAT,                                             \
EQUIPMENT_TYPES::ARMORE_SLOT_HEAD,                                 \
EQUIPMENT_TYPES::ARMORE_SLOT_BODY,                                 \
EQUIPMENT_TYPES::ARMORE_SLOT_ARMS,                                 \
EQUIPMENT_TYPES::ARMORE_SLOT_LEGS,                                 \
EQUIPMENT_TYPES::WEAPON_LEFT,                                      \
EQUIPMENT_TYPES::WEAPON_RIGHT} [i];

Equipment::Equipment(int_s slotCount) {
    slotCount += ((slotCount < 5) ? (5-slotCount) : (0));
    //cout<<"SC"<<slotCount<<endl;
    slots = std::vector<Slot>(slotCount);
    for(int i =0; i<5;i++) {
        Slot sl;sl.type=EQUIPMENTELEMENTS(i);
        slots.push_back(sl);
    }
}

int Equipment::size() {
    return slots.size();
}