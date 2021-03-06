#pragma once

#include <map>

#include "../Tool/Weapon/Weapon.h"
#include "../Tool/Armor/Armor.h"

class Player {

public:
	// BEGIN---------------------------------------------- CONSTRUCTOR ------------------------------------------------
	Player(string_t type, string_t name, uint_t attack_rate = 0, uint_t attack_speed = 0, string_t attack_type = "None") :
		type_(type),
		name_(name),
		attack_rate_(attack_rate),
		attack_speed_(attack_speed),
		attack_type_(attack_type) {

	}
	// END------------------------------------------------ CONSTRUCTOR ------------------------------------------------

	// BEGIN---------------------------------------------- GETTERS ----------------------------------------------------
	string_t name() const {
		return name_;
	}

	uint_t attack_rate() const {
		return attack_rate_;
	}

	uint_t attack_speed() const {
		return attack_speed_;
	}

	string_t attack_type() const {
		return attack_type_;
	}

	uint_t hp() const {
		return hp_;
	}

	uint_t total_hp() const {
		return total_hp_;
	}

	uint_t level() const {
		return level_;
	}

	uint_t experience() const {
		return experience_;
	}
	// END------------------------------------------------ GETTERS ----------------------------------------------------


	// BEGIN---------------------------------------------- SETTERS ----------------------------------------------------
	void set_name(string_t name) {
		name_ = name;
	}

	void set_hp(uint_t hp) {
		hp_ = hp;
	}

	void set_total_hp(uint_t total_hp) {
		total_hp_ = total_hp;
	}

	void set_level(uint_t level) {
		level_ = level;
	}

	void set_experience(uint_t experience) {
		experience_ = experience;
	}
	// END------------------------------------------------ SETTERS ----------------------------------------------------

	void add_tool(Tool* tool) {
		tools_[tool->name()] = tool;
	}

	void set_weapon(string_t name) {
		for (auto k : tools_) {
			if (k.first == name && (k.second)->type() == "weapon") {
				weapon_ = k.second;
				return;
			}
		}

		printf("No such weapon\n");
		exit(1);
	}

	void set_armor(string_t name) {
		for (auto k : tools_) {
			printf("%s %s\n", k.first, k.second->type());
			if (k.first == name && (k.second)->type() == "armor") {
				armor_ = k.second;
				return;
			}
		}

		printf("No such armor\n");
		exit(1);
	}

	void unset_weapon() {
		weapon_ = nullptr;
	}

	void unset_armor() {
		armor_ = nullptr;
	}

	void print_weapon(string_t header = "") const {
		if (header) {
			printf("%s ", header);
		}

		if (weapon_) {
			printf("%s\n\n", weapon_->name());
		} else {
			printf("not set\n\n");
		}
	}

	void print_armor(string_t header = "") const {
		if (header) {
			printf("%s ", header);
		}

		if (armor_) {
			printf("%s\n\n", armor_->name());
		} else {
			printf("not set\n\n");
		}
	}

	void print_tools(string_t header = "") const {
		if (header) {
			printf("%s\n", header);
		}

		for (auto k : tools_) {
			printf("\tName: \"%s\"\n", k.first);
			printf("\tType: \"%s\"\n", k.second->type());

			printf("\n");
		}

		printf("\n");
	}

	void info() {
		for (int i = 0; i < 50; i++)
			printf("-");

		printf("\n");

		printf("Name: \"%s\"\n\n", name_);
		printf("Type: \"%s\"\n\n", type_);

		print_tools("Tools:");

		for (int i = 0; i < 50; i++)
			printf("-");

		printf("\n");
	}

	// BEGIN---------------------------------------------- DESTRUCTOR -------------------------------------------------
	virtual ~Player() {}
	// END------------------------------------------------ DESTRUCTOR -------------------------------------------------

protected:
	string_t type_;

	string_t name_;

	uint_t hp_;
	uint_t total_hp_;

	uint_t level_;
	uint_t experience_;

	uint_t attack_rate_;
	uint_t attack_speed_;

	string_t attack_type_;

	Tool* weapon_;
	Tool* armor_;

	std::map<string_t, Tool*> tools_;
};
