//
// Flame.cpp for bomberman in /u/epitech_2014/el-out_y/public/bomberman/chen_b
// 
// Made by laurent chen
// Login   <chen_b@epitech.net>
// 
// Started on  Wed Jun  1 13:25:54 2011 laurent chen
// Last update Sun Jun  5 22:27:57 2011 luc ngauv
//

#include "AnimStates.hpp"
#include "Flame.hpp"
#include "MyGame.hpp"
#include "Bonus.hpp"

Flame::Flame(float const x, float const z, int const pow, e_direction const dir, Camera const &camera, std::list<AObject*> *objs, gdl::Image const &texture)
  : AObject(FIRE), objs_(objs), isExpand_(false), power_(pow), camera_(camera), dir_(dir), texture_(texture)
{
  this->position_.x = x;
  this->position_.y = 0.0f;
  this->position_.z = z;
  this->initialize();
}

Flame::~Flame()
{}

int		Flame::getPower_(void) const
{
  return (this->power_);
}

void		Flame::setPower_(int power_)
{
  this->power_ = power_;
}

e_direction	Flame::getDir_(void) const
{
  return (this->dir_);
}

void		Flame::setDir_(e_direction dir)
{
  this->dir_ = dir;
}

void		Flame::expand(void)
{
  if (this->dir_ == UP && this->power_ != 0)
    this->objs_->push_front(new Flame(this->position_.x,
				      this->position_.z + (BLOCK_SIZE * 2),
				      (this->power_ - 1),
				      this->dir_,
				      this->camera_,
				      this->objs_, this->texture_));
  else if (this->dir_ == DOWN && this->power_ != 0)
    this->objs_->push_front(new Flame(this->position_.x,
				      this->position_.z - (BLOCK_SIZE * 2),
				      (this->power_ - 1),
				      this->dir_,
				      this->camera_,
				      this->objs_, this->texture_));
  else if (this->dir_ == RIGHT && this->power_ != 0)
    this->objs_->push_front(new Flame(this->position_.x - (BLOCK_SIZE * 2),
				      this->position_.z,
				      (this->power_ - 1),
				      this->dir_,
				      this->camera_,
				      this->objs_, this->texture_));
  else if (this->dir_ == LEFT && this->power_ != 0)
    this->objs_->push_front(new Flame(this->position_.x + (BLOCK_SIZE * 2),
				      this->position_.z,
				      (this->power_ - 1),
				      this->dir_,
				      this->camera_,
				      this->objs_, this->texture_));
}

void		Flame::initialize(void)
{
  this->timer_.play();
}


void		Flame::createBonus(void)
{
  int		value;

  if ((value = rand() % 6 + 7) < 10)
    this->objs_->push_back(new Bonus(this->position_.x, this->position_.z, this->camera_, value));
}

void		Flame::destroyObjects(void)
{
  std::list<AObject *>::iterator it = this->objs_->begin();

  for (; it != this->objs_->end() && this->isOver_ == false; it++)
    {
      if (((*it)->getType() == BWALL || (*it)->getType() == BONUS)
	  && this->checkCollision((*it)->getPos().x, (*it)->getPos().z)  == true)
	{
	  this->isOver_ = true;
	  delete *it;
	  objs_->erase(it);
	  if ((*it)->getType() == BWALL)
	    this->createBonus();
	  break;
	}
      else if (((*it)->getType() == PLAYER || (*it)->getType() == UBWALL) &&
	       this->checkCollision((*it)->getPos().x, (*it)->getPos().z)  == true)
      	{
	  if ((*it)->getType() != UBWALL)
	    {
	      delete *it;
	      objs_->erase(it);
	    }
	  else
	    this->isOver_ = true;
      	  break;
      	}
    }
}


void		Flame::update(gdl::GameClock const & gameClock, gdl::Input &input)
{
  (void)gameClock;
  (void)input;

  this->destroyObjects();
  if (this->isOver_ == false)
    {
      this->timer_.update();
      if (this->isExpand_ == false)
	{
	  this->expand();
	  this->isExpand_ = true;
	}
      if (this->timer_.getTotalElapsedTime() >= 0.5)
	this->isOver_ = true;
    }
}

void		Flame::draw(void)
{
  if (this->isOver_ == false)
    {
      this->texture_.bind();
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
      glTexCoord2f(0.0f, 1.0f);
      glVertex3f(BLOCK_SIZE,-BLOCK_SIZE,BLOCK_SIZE);
      glTexCoord2f(1.0f, 1.0f);
      glVertex3f(BLOCK_SIZE,-BLOCK_SIZE,-BLOCK_SIZE);
      glTexCoord2f(1.0f, 0.0f);
      glVertex3f(BLOCK_SIZE,BLOCK_SIZE,-BLOCK_SIZE);

      glTexCoord2f(0.0f, 0.0f);
      glVertex3f(-BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE);
      glTexCoord2f(0.0f, 1.0f);
      glVertex3f(-BLOCK_SIZE,-BLOCK_SIZE,BLOCK_SIZE);
      glTexCoord2f(1.0f, 1.0f);
      glVertex3f(-BLOCK_SIZE,-BLOCK_SIZE,-BLOCK_SIZE);
      glTexCoord2f(1.0f, 0.0f);
      glVertex3f(-BLOCK_SIZE,BLOCK_SIZE,-BLOCK_SIZE);

      glTexCoord2f(0.0f, 0.0f);
      glVertex3f(-BLOCK_SIZE,BLOCK_SIZE,-BLOCK_SIZE);
      glTexCoord2f(0.0f, 1.0f);
      glVertex3f(-BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE);
      glTexCoord2f(1.0f, 1.0f);
      glVertex3f(BLOCK_SIZE,BLOCK_SIZE,BLOCK_SIZE);
      glTexCoord2f(1.0f, 0.0f);
      glVertex3f(BLOCK_SIZE,BLOCK_SIZE,-BLOCK_SIZE);

      glEnd();
      glPopMatrix();
    }
}
