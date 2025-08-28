/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcombo <lcombo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:25:13 by lcombo            #+#    #+#             */
/*   Updated: 2022/11/01 01:42:17 by lcombo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called\n";
    name = "[Default]";
    points_hit = 10;
    points_energy = 10;
    damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "name constructor called\n";
    this->name = name;
    points_hit = 10;
    points_energy = 10;
    damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
    std::cout << "Copy constructor called\n";
    name = src.getName();
    points_hit = src.getHit();
    points_energy = src.getEnergy();
    damage = src.getDamage();
}

std::string ClapTrap::getName() const
{
    return (name);
}

unsigned int ClapTrap::getHit() const
{
    return (points_hit);
}

unsigned int ClapTrap::getEnergy() const
{
    return (points_energy);
}

unsigned int ClapTrap::getDamage() const
{
    return (damage);
}

void ClapTrap::attack(const std::string& target)
{
    if (getHit() <= 0)
    {
        std::cout << "ClapTrap " << getName() << " died...\n";
        return ;
    }
    if (getEnergy() == 0)
    {
        std::cout << "ClapTrap " << getName() << " have not enough energy!\n";
        return ;
    }
    points_energy--;
    std::cout << "ClapTrap " << getName() << " attacks " << target << \
	", causing " << getDamage() << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (getHit() <= 0)
    {
        std::cout << "ClapTrap " << getName() << " died...\n";
        return ;
    }
    if (getHit() <= amount)
    {
        points_hit = 0;
        std::cout << "ClapTrap " << getName() << " take " << amount << \
    " points of damage and is dead now!\n";
    }
    else
    {
        points_hit -= amount;
        std::cout << "ClapTrap " << getName() << " take " << amount << \
    " points of damage! " << getHit() << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (getHit() <= 0)
    {
        std::cout << "ClapTrap " << getName() << " died...\n";
        return ;
    }
    if (getEnergy() <= 0)
    {
        std::cout << "ClapTrap " << getName() << " have not enough energy!\n";
        return ;
    }
    points_hit += amount;
    std::cout << "ClapTrap " << getName() << " got repaired " << amount << \
	" points! " << getHit() << std::endl;
    points_energy--;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called\n";
}