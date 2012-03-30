//
// Wall.cpp for ok in /u/all/el-out_y/public/bomberman/garbo_r
// 
// Made by robin garbo
// Login   <garbo_r@epitech.net>
// 
// Started on  Sat May 28 18:01:26 2011 robin garbo
// Last update Sun Jun  5 18:39:43 2011 luc ngauv
//

#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Wall.hpp"
#include "Camera.hpp"

Wall::Wall(int const x, int const y, Camera const &camera, gdl::Image const &texture)
  : AObject(UBWALL), texture_(texture), camera(camera)
{
  this->position_.x = x * (BLOCK_SIZE * 2);
  this->position_.y = 0.0f;
  this->position_.z = y * (BLOCK_SIZE * 2);
}

void		Wall::initialize()
{}

void		Wall::draw()
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

  glEnd();
  glRotatef(this->camera.getRot().x , 1.0f, 0.0f, 0.0f);
  glRotatef(this->camera.getRot().y , 0.0f, 1.0f, 0.0f);
  glRotatef(this->camera.getRot().z , 0.0f, 0.0f, 1.0f);

  glPopMatrix();
}

void		Wall::update(gdl::GameClock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
}
