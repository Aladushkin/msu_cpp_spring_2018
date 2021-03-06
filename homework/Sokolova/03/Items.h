/**
@file
@brief Header file with item classes declaration.

File contains hierarchy of buyable items in the game.
*/


/**
 * @brief Interface of buyable items.
 * Can be bought.
 */
class Buyable {
public:
    virtual void beBought();
};

/**
 * @brief Base class of all items.
 * Item has a unique id. 
 * Every item can be bought so has some cost.
 * Item can be worn out and can be renewed.
 * Item can be upgraded to new level.
 * 
 * Must implement beBought() method.
 */
class Item: public Buyable {
    int id;
    int cost;
    int state;
    int level;
    int power;
public:
    void renew();
    void upgrade();
};

/**
 * @brief Interface of attacking items.
 * 
 */
class Attacker {
public:
    virtual void attack(int);
};

/**
 * @brief Base class of weapons.
 * Every weapon has a list of actions that can be done with it.
 * Weapon is attacker.
 */
class Weapon: public Item, public Attacker {
    int actions[];
public:
    void attack(int action);
};

/**
 * @brief Bow attacks with arrows.
 * Available actions: shoot, beat with arc.
 * Main advantage: can be used from far of enemy.
 * Upgrade: increase number of arrows that can be used in a row.
 */
class Bow: public Weapon {
    int arrows;
};

/**
 * @brief Shovel attacks with blade.
 * Available actions: cut with blade, beat with handle.
 * Main advantage: can be used suddenly.
 * Upgrade: increase in weight and blade sharpening.
 */
class Shovel: public Weapon {
    int weight;
    int sharpness;
};

/**
 * @brief Sword attacks with blade.
 * Available actions: several special methods.
 * Main advantage: diversity of actions.
 * Upgrade: longen, sharpen.
 */
class Sword: public Weapon {
};


class Defender {
public:
    virtual void defend(int);
};

/**
 * @brief Base class of armor.
 * Main armor function is to defend.
 * Power defines the power of attack it can repel.
 */
class Armor: public Item {
    int defences[];
public:
    void defend(int defence);
};

/**
 * @brief Hauberk can defend of shovel and somehow of arrows but cannot defend of sword.
 */
class Hauberk: public Armor {
};

/**
 * @brief Lats can defend of everything exept beats with heavy stuff.
 */
class Lats: public Armor {
};

/**
 * @brief Basin can defend of everything in one-to-one fight but is useless in far distance.
 */
class Basin: public Armor {
};
