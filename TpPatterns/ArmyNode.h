#pragma once

#include <vector>
#include <cstddef>

class ArmyNode {
public:
    virtual ~ArmyNode() = default;

    virtual double GetHealth() const = 0;
    virtual double GetDamage() const = 0;
    virtual double GetEarnings() const = 0;
    virtual void ToHit(double damage) = 0;
    virtual std::size_t CountUnits() const = 0;
};

//----------------------------------------------------------------------------------------------------------------------

class CompositeNode: public ArmyNode {
public:
    double GetHealth() const override;
    double GetDamage() const override;
    double GetEarnings() const override;
    void ToHit(double damage) override;
    std::size_t CountUnits() const override;
    virtual std::size_t GetSize() const;
    virtual const ArmyNode& GetSubnode(std::size_t subnode_number) const;
    virtual void AddNewSubnode(ArmyNode* const& new_subnode);
    virtual bool IsEmpty() const;
protected:
    std::vector<ArmyNode*> subnodes;
};