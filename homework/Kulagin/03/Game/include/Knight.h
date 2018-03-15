#pragma once

#include "Player.h"

class Knight : Player {

public:
	// BEGIN---------------------------------------------- CONSTRUCTOR ------------------------------------------------
	Knight(): Player() {
		attack_type_ = "pierce";

		type_ = "knight";
	}
	// END------------------------------------------------ CONSTRUCTOR ------------------------------------------------

	// BEGIN---------------------------------------------- DESTRUCTOR -------------------------------------------------
	~Knight() {}
	// END------------------------------------------------ DESTRUCTOR -------------------------------------------------

private:
};