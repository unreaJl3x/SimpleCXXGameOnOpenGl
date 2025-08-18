#include "Obj.h"

entity *Obj::ConvertToEntity() {
    entity* en = new entity(name+"_OBJ",true, -1);
    en->AddSprite("front",this->sprite);
    //en->SetTransform(player.x player.y);

    return en;
}