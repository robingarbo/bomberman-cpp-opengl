//
// Camera.cpp for bomberman in /home/chen_b//BOMBERMAN/GDL
// 
// Made by laurent chen
// Login   <chen_b@epitech.net>
// 
// Started on  Thu May 26 16:18:14 2011 laurent chen
// Last update Sun Jun  5 23:37:21 2011 luc ngauv
//

#include <cstdlib>
#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Camera.hpp"

Camera::Camera(void)
  : position_(0.0f, 0.0f, 5510.0f), rotation_(0.0f, 0.0f, 0.0f)
{
}

void Camera::initialize(std::list<AObject *> *list, bool follow)
{
  this->list_ = list;
  this->player_ = NULL;
  this->follow_ = follow;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0f, 800.0f/600.0f, 2.0f, 50000.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(position_.x, position_.y, position_.z,
	    position_.x, 0.0f, position_.z + 50,
	    00.0f, 1.0f, 0.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
}

void Camera::ini_menu(void)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0f, 800.0f/600.0f, 2.0f, 50000.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(position_.x, position_.y, position_.z,
  	    0.0f, 0.0f, -1.0f,
  	    0.0f, 1.0f, 0.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
}

AObject		 *Camera::catchPlayer(void)
{
  std::list<AObject*>::iterator itb = this->list_->begin();
  for (; itb != this->list_->end(); ++itb)
    if ((*itb)->getType() == PLAYER)
      return ((*itb));
  return (NULL);
}

void  Camera::update(gdl::GameClock const & gameClock, gdl::Input & input)
{
  (void)gameClock;
  (void)input;
  if (this->follow_ == true)
    {
      this->position_.y = 10500;
      if ((this->player_ = this->catchPlayer()) != NULL)
	{
	  this->position_.x = this->player_->getPos().x;
	  this->position_.z = this->player_->getPos().z;
	}
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluPerspective(70.0f, 800.0f/600.0f, 2.0f, 50000.0f);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      gluLookAt(position_.x, position_.y, position_.z,
		position_.x, 0.0f, position_.z + 50,
		00.0f, 1.0f, 0.0f);
      glEnable(GL_DEPTH_TEST);
      glDepthFunc(GL_LEQUAL);
    }
  else
    {
      this->position_.y = 7000;
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluPerspective(70.0f, 800.0f/600.0f, 2.0f, 50000.0f);
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      gluLookAt(position_.x, position_.y, position_.z,
		position_.x, 0.0f, position_.z + 50,
		00.0f, 1.0f, 0.0f);
      glEnable(GL_DEPTH_TEST);
      glDepthFunc(GL_LEQUAL);
    }
}

Vector3f Camera::getPos(void) const
{
  return (this->position_);
}

Vector3f Camera::getRot(void) const
{
  return (this->rotation_);
}

void	Camera::setPosition_(Vector3f npos)
{
  this->position_ = npos;
}
