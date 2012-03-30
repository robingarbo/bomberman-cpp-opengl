//
// Bonus.cpp for Bomberman in /home/chen_b//BOMBERMAN/chen_b
// 
// Made by laurent chen
// Login   <chen_b@epitech.net>
// 
// Started on  Thu Jun  2 20:30:00 2011 laurent chen
// Last update Sun Jun  5 00:23:36 2011 robin garbo
//

#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Image.hpp"
#include "Color.hpp"
#include "Bonus.hpp"
#include "MyGame.hpp"

Bonus::Bonus() : AObject(BONUS)
{
  this->position_.x = 0.0f;
  this->position_.y = 0.0f;
  this->position_.z = 0.0f;
  this->bType_ = BONUS_SPEED;
  this->initialize();
}

Bonus::Bonus(float x, float z, Camera const &camera, int type) : AObject(BONUS)
{
  this->position_.x = x;
  this->position_.y = 0.0f;
  this->position_.z = z;
  this->bType_ = type;
  this->camera_ = camera;
  this->initialize();
}

Bonus::Bonus(Bonus const &c) : AObject(BONUS)
{
  this->camera_ = c.camera_;
  this->position_.x = c.position_.x;
  this->position_.y = c.position_.y;
  this->position_.z = c.position_.z;
  this->bType_ = c.bType_;
  this->initialize();
}

Bonus& Bonus::operator=(Bonus const &c)
{
  this->camera_ = c.camera_;
  this->position_.x = c.position_.x;
  this->position_.y = c.position_.y;
  this->position_.z = c.position_.z;
  this->bType_ = c.bType_;
  return (*this);
}

Bonus::~Bonus()
{
}

int		Bonus::getBType_(void) const
{
  return (this->bType_);
}

void		Bonus::initialize(void)
{
  if (this->bType_ == BONUS_SPEED)
    this->texture_ = gdl::Image::load("assets/textures/bonus_speed.jpg");
  else if (this->bType_ == BONUS_BOMB)
    this->texture_ = gdl::Image::load("assets/textures/bonus_bomb.png");
  else
    this->texture_ = gdl::Image::load("assets/textures/bonus_flame.png");
}

void		Bonus::update(gdl::GameClock const & gameClock,
			      gdl::Input &input)
{
  int		y = this->rotation_.y;

  y = (y + 5) % 360;
  this->rotation_.y = y;
  (void)gameClock;
  (void)input;
}

void            Bonus::draw(void)
{
  this->texture_.bind();
  glEnable(GL_TEXTURE_2D);
  glPushMatrix();
  glTranslatef(this->position_.x, this->position_.y, this->position_.z);
  glRotatef(this->rotation_.y, 0.0f, 1.0f, 0.0f);
  glBegin(GL_QUADS);

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f((BLOCK_SIZE-100), (BLOCK_SIZE-100), BLOCK_SIZE-100);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(BLOCK_SIZE-100, -(BLOCK_SIZE-100), BLOCK_SIZE-100);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(-(BLOCK_SIZE-100), -(BLOCK_SIZE-100), BLOCK_SIZE-100);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(-(BLOCK_SIZE-100), BLOCK_SIZE-100, BLOCK_SIZE-100);

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(BLOCK_SIZE-100, (BLOCK_SIZE-100), -(BLOCK_SIZE-100));
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f((BLOCK_SIZE-100), -(BLOCK_SIZE-100), -(BLOCK_SIZE-100));
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(-(BLOCK_SIZE-100), -(BLOCK_SIZE-100), -(BLOCK_SIZE-100));
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(-(BLOCK_SIZE-100), (BLOCK_SIZE-100), -(BLOCK_SIZE-100));

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f((BLOCK_SIZE-100), (BLOCK_SIZE-100), (BLOCK_SIZE-100));
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f((BLOCK_SIZE-100), -(BLOCK_SIZE-100), (BLOCK_SIZE-100));
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f((BLOCK_SIZE-100), -(BLOCK_SIZE-100), -(BLOCK_SIZE-100));
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f((BLOCK_SIZE-100), (BLOCK_SIZE-100), -(BLOCK_SIZE-100));

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(-(BLOCK_SIZE-100), (BLOCK_SIZE-100), (BLOCK_SIZE-100));
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(-(BLOCK_SIZE-100), -(BLOCK_SIZE-100), (BLOCK_SIZE-100));
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(-(BLOCK_SIZE-100), -(BLOCK_SIZE-100), -(BLOCK_SIZE-100));
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(-(BLOCK_SIZE-100), (BLOCK_SIZE-100), -(BLOCK_SIZE-100));

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(-(BLOCK_SIZE-100), (BLOCK_SIZE-100), -(BLOCK_SIZE-100));
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(-(BLOCK_SIZE-100), (BLOCK_SIZE-100), (BLOCK_SIZE-100));
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f((BLOCK_SIZE-100), (BLOCK_SIZE-100), (BLOCK_SIZE-100));
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f((BLOCK_SIZE-100), (BLOCK_SIZE-100), -(BLOCK_SIZE-100));

  glEnd();
  glRotatef(this->camera_.getRot().x , 1.0f, 0.0f, 0.0f);
  glRotatef(this->camera_.getRot().y , 0.0f, 1.0f, 0.0f);
  glRotatef(this->camera_.getRot().z , 0.0f, 0.0f, 1.0f);
  glPopMatrix();
}
