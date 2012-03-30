//
// AObject.cpp for ok in /u/all/el-out_y/public/bomberman/garbo_r
// 
// Made by robin garbo
// Login   <garbo_r@epitech.net>
// 
// Started on  Tue May 31 19:44:16 2011 robin garbo
// Last update Sun Jun  5 00:39:40 2011 robin garbo
//

#include <iostream>

#include "AObject.hpp"

AObject::AObject(void)
  : position_(0.0f, 0.0f, 0.0f), rotation_(0.0f, 0.0f, 0.0f), type_(0), isOver_(false)
{}

AObject::AObject(int type)
  : position_(0.0f, 0.0f, 0.0f), rotation_(0.0f, 0.0f, 0.0f), type_(type), isOver_(false)
{}

AObject::~AObject(void) {}

Vector3f AObject::getPos(void) const
{
  return (this->position_);
}

int AObject::getType(void) const
{
  return (this->type_);
}

Vector3f AObject::getRot(void) const
{
  return (this->rotation_);
}

bool	 AObject::checkCollision(float xmap, float zmap)
{
  if (this->position_.x - xmap - BLOCK_SIZE * 1.25 > 0)
    return false;
  if (this->position_.z - zmap - BLOCK_SIZE * 1.25 > 0)
    return false;
  if (this->position_.x > xmap - BLOCK_SIZE * 1.5 || this->position_.x > xmap + BLOCK_SIZE * 1.25)
    if (this->position_.z > zmap - BLOCK_SIZE * 1.5 || this->position_.z > zmap + BLOCK_SIZE * 1.25)
      return true;
  return false;
}
bool	AObject::isOver(void) const
{
  return this->isOver_;
}
