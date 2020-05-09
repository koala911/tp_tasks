#include "ArmyNode.h"

void CompositeNode::ToHit(double damage) {
    for (ArmyNode* subnode: subnodes) {
        subnode->ToHit(damage / subnodes.size());
    }
}

double CompositeNode::GetDamage() const {
    double total_damage = 0;
    for (const ArmyNode* subnode: subnodes) {
        total_damage += subnode->GetDamage();
    }
    return total_damage;
}

double CompositeNode::GetHealth() const {
    double total_health = 0;
    for (const ArmyNode* subnode: subnodes) {
        total_health += subnode->GetHealth();
    }
    return total_health;
}

double CompositeNode::GetEarnings() const {
    double total_earnings = 0;
    for (const ArmyNode* subnode: subnodes) {
        total_earnings += subnode->GetEarnings();
    }
    return total_earnings;
}

std::size_t CompositeNode::CountUnits() const {
    std::size_t total_units = 0;
    for (const ArmyNode* subnode: subnodes) {
        total_units += subnode->CountUnits();
    }
    return total_units;
}

std::size_t CompositeNode::GetSize() const {
    return subnodes.size();
}

const ArmyNode& CompositeNode::GetSubnode(std::size_t subnode_number) const {
    return *subnodes[subnode_number];
}

void CompositeNode::AddNewSubnode(ArmyNode* const& new_subnode) {
    subnodes.push_back(new_subnode);
}

bool CompositeNode::IsEmpty() const {
    return subnodes.empty();
}