//
// BreakableWall.cpp for  in /u/all/el-out_y/public/bomberman/garbo_r
// 
// Made by mickael mendel
// Login   <mendel_m@epitech.net>
// 
// Started on  Sun May 29 14:13:07 2011 mickael mendel
// Last update Sun Jun  5 18:22:33 2011 luc ngauv
//

#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Wall.hpp"
#include "BreakableWall.hpp"
#include "Floor.hpp"

BreakableWall::BreakableWall(int const x, int const y, int const bonus, Camera const &camera, gdl::Image const &texture)
  : Wall(x, y, camera, texture), broken_(false), bonus_(bonus)
{
  this->type_ = BWALL;
}

void		BreakableWall::initialize()
{}

void		BreakableWall::draw()
{
  texture_.bind();
  glEnable(GL_TEXTURE_2D);
  glPushMatrix();
  glTranslatef(this->position_.x, this->position_.y, this->position_.z);
  glBegin(GL_QUADS);

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(BLOCK_SIZE,-BLOCK_SIZE,BLOCK_SIZE);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(-BLOCK_SIZE,-BLOCK_SIZE,BLOCK_SIZE);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(-BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE);

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(BLOCK_SIZE,BLOCK_SIZE,-BLOCK_SIZE);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(BLOCK_SIZE,-BLOCK_SIZE,-BLOCK_SIZE);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(-BLOCK_SIZE,-BLOCK_SIZE,-BLOCK_SIZE);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(-BLOCK_SIZE,BLOCK_SIZE,-BLOCK_SIZE);

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE);
  glVertex3f(BLOCK_SIZE,-BLOCK_SIZE,BLOCK_SIZE);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(BLOCK_SIZE,-BLOCK_SIZE,-BLOCK_SIZE);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(BLOCK_SIZE,BLOCK_SIZE,-BLOCK_SIZE);

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(-BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE);
  glVertex3f(-BLOCK_SIZE,-BLOCK_SIZE,BLOCK_SIZE);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(-BLOCK_SIZE,-BLOCK_SIZE,-BLOCK_SIZE);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(-BLOCK_SIZE,BLOCK_SIZE,-BLOCK_SIZE);

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(-BLOCK_SIZE,BLOCK_SIZE,-BLOCK_SIZE);
  glVertex3f(-BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(BLOCK_SIZE,BLOCK_SIZE,-BLOCK_SIZE);
  glRotatef(this->camera.getRot().x +
	       this->position_.x,
	       this->camera.getRot().y +
	       this->position_.y,
	       this->camera.getRot().z +
	       this->position_.z, 0.0f);

  glEnd();
  glPopMatrix();
}

void		BreakableWall::update(gdl::GameClock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
}

bool		BreakableWall::isBroken(void) const
{
  return this->broken_;
}

int		BreakableWall::getBonus(void) const
{
  return this->bonus_;
}
