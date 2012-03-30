//
// Floor.cpp for  in /u/all/el-out_y/public/bomberman/garbo_r
// 
// Made by mickael mendel
// Login   <mendel_m@epitech.net>
// 
// Started on  Sun May 29 14:35:50 2011 mickael mendel
// Last update Sun Jun  5 18:24:53 2011 luc ngauv
//

#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <Image.hpp>

#include "Floor.hpp"

Floor::Floor(int const x, int const y, Camera const &camera, gdl::Image const &texture)
  : AObject(FLOOR), texture_(texture), camera(camera)
{
  this->position_.x = x * (BLOCK_SIZE * 2);
  this->position_.y = 0.0f;
  this->position_.z = y * (BLOCK_SIZE * 2);
  this->camera = camera;
}

void Floor::initialize(void)
{
}

void Floor::update(gdl::GameClock const & gameClock, gdl::Input & input)
{
  (void)gameClock;
  (void)input;
}

void Floor::draw(void)
{
  texture_.bind();
  glEnable(GL_TEXTURE_2D);
  glPushMatrix();
  glTranslatef(this->position_.x, this->position_.y, this->position_.z);

  glBegin(GL_QUADS);

  glTexCoord2f(0.0f, 0.0f);
  glVertex3f(-BLOCK_SIZE,-BLOCK_SIZE,-BLOCK_SIZE);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f(-BLOCK_SIZE,-BLOCK_SIZE,BLOCK_SIZE);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f(BLOCK_SIZE,-BLOCK_SIZE,BLOCK_SIZE);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f(BLOCK_SIZE,-BLOCK_SIZE,-BLOCK_SIZE);
  glRotatef(this->camera.getRot().x +
	       this->position_.x,
	       this->camera.getRot().y +
	       this->position_.y,
	       this->camera.getRot().z +
	       this->position_.z, 0.0f);
  glEnd();
  glPopMatrix();
}
