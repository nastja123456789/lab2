#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>



class Restaurant
{
public:
    Restaurant();
    Restaurant(std::string name) : name(name){};
    Restaurant(const char *name) : name(name){};
    size_t hash() const {
        return std::hash<std::string>{}("Restaurant" + name);
    }


    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Restaurant::name = name;
    }

    bool operator==(const Restaurant &other) const {
        return getName() == other.getName();
    }

    bool operator!=(const Restaurant &other) const {
        return !(this->operator==(other));
    }

    std::string toString() const {
        return name;
    }

private:
    std::string name;
};

#endif // RESTAURANT_H
