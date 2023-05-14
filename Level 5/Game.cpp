#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Forward declaration of the Ability class
class Ability;

// Character class
class Character {
protected:
    string name;
    int health;
    int level;

public:
    Character(const string& name, int health, int level)
        : name(name), health(health), level(level) {}

    virtual void useAbility(const Ability& ability) = 0;

    void displayStatus() const {
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Level: " << level << endl;
    }
};

// Ability class
class Ability {
protected:
    string name;
    int damage;
    int manaCost;

public:
    Ability(const string& name, int damage, int manaCost)
        : name(name), damage(damage), manaCost(manaCost) {}

    virtual void execute() const = 0;

    void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Damage: " << damage << endl;
        cout << "Mana Cost: " << manaCost << endl;
    }
};

// Warrior class
class Warrior : public Character {
public:
    Warrior(const string& name, int health, int level)
        : Character(name, health, level) {}

    void useAbility(const Ability& ability) override {
        cout << "Warrior " << name << " is using the ability: " << ability.displayInfo() << endl;
        // Perform additional logic specific to the Warrior's ability
        // ...
    }
};

// Archer class
class Archer : public Character {
public:
    Archer(const string& name, int health, int level)
        : Character(name, health, level) {}

    void useAbility(const Ability& ability) override {
        cout << "Archer " << name << " is using the ability: " << ability.displayInfo() << endl;
        // Perform additional logic specific to the Archer's ability
        // ...
    }
};

// Mage class
class Mage : public Character {
public:
    Mage(const string& name, int health, int level)
        : Character(name, health, level) {}

    void useAbility(const Ability& ability) override {
        cout << "Mage " << name << " is using the ability: " << ability.displayInfo() << endl;
        // Perform additional logic specific to the Mage's ability
        // ...
    }
};

int main() {
    // Create characters
    Warrior warrior("Warrior", 100, 5);
    Archer archer("Archer", 80, 4);
    Mage mage("Mage", 60, 3);

    // Create abilities
    Ability ability1("Ability 1", 20, 10);
    Ability ability2("Ability 2", 30, 15);
    Ability ability3("Ability 3", 40, 20);

    // Display character status
    warrior.displayStatus();
    archer.displayStatus();
    mage.displayStatus();

    // Use abilities
    warrior.useAbility(ability1);
    archer.useAbility(ability2);
    mage.useAbility(ability3);

    return 0;
}
