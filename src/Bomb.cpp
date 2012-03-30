//
// Bomb.cpp for bomberman in /u/all/el-out_y/public/bomberman/chen_b
// 
// Made by laurent chen
// Login   <chen_b@epitech.net>
// 
// Started on  Tue May 31 22:19:09 2011 laurent chen
// Last update Sun Jun  5 22:25:53 2011 luc ngauv
//

#include "Flame.hpp"
#include "AnimStates.hpp"
#include "Bomb.hpp"
#include "MyGame.hpp"

namespace	Bomb
{
  Bombe::Bombe(float const x, float const z, int const id, int const pow, Camera const &camera, Perso::Personnage *pl, std::list<AObject*> *objs, gdl::Image const & iFire)
    : AObject(BOMB), id_(id), power_(pow), camera_(camera), pl_(pl), objs_(objs), iFire_(iFire)
  {
    this->position_.x = x;
    this->position_.y = 0.0f;
    this->position_.z = z;
    this->initialize();
  }

  Bombe::~Bombe()
  {}

  int		Bombe::getPower_(void) const
  {
    return (this->power_);
  }

  void		Bombe::setPower_(int pow)
  {
    this->power_ = pow;
  }

  int		Bombe::getId_() const
  {
    return (this->id_);
  }

  void          Bombe::setId_(int id)
  {
    this->id_ = id;;
  }

  void		Bombe::adjPos(void)
  {
    int		x = this->position_.x;
    int		z = this->position_.z;

    if (x % (BLOCK_SIZE * 2) > BLOCK_SIZE)
      x += (BLOCK_SIZE * 2 - (x % (BLOCK_SIZE * 2)));
    else
      x -= x % (BLOCK_SIZE * 2);
    if (z % (BLOCK_SIZE * 2) > BLOCK_SIZE)
      z += (BLOCK_SIZE * 2 - (z % (BLOCK_SIZE * 2)));
    else
      z -= z % (BLOCK_SIZE * 2);
    this->position_.x = x;
    this->position_.z = z;
  }

  void		Bombe::explose(void)
  {
    this->pl_->setNbomb_(this->pl_->getNbomb_() + 1);
    this->isOver_ = true;
    this->objs_->push_front(new Flame(this->position_.x,
				      this->position_.z,
				      this->power_, UP, this->camera_,
				      this->objs_, this->iFire_));
    this->objs_->push_front(new Flame(this->position_.x,
				      this->position_.z,
				      this->power_, DOWN, this->camera_,
				      this->objs_, this->iFire_));
    this->objs_->push_front(new Flame(this->position_.x,
				      this->position_.z,
				      this->power_, LEFT, this->camera_,
				      this->objs_, this->iFire_));
    this->objs_->push_front(new Flame(this->position_.x,
				      this->position_.z,
				      this->power_, RIGHT, this->camera_,
				      this->objs_, this->iFire_));
  }

  void		Bombe::initialize(void)
  {
    this->adjPos();
    this->pl_->setNbomb_(this->pl_->getNbomb_() - 1);
    this->model_ = gdl::Model::load("assets/models/bomb.fbx");
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(this->position_.x + this->camera_.getPos().x,
                 this->position_.y + this->camera_.getPos().y,
                 this->position_.z + this->camera_.getPos().z);
    glPopMatrix();
    this->timer_.play();
  }

  void		Bombe::update(gdl::GameClock const & gameClock, gdl::Input &input)
  {
    (void)input;
    if (this->isOver_ == false)
      {
	std::list<AObject *>::iterator it = this->objs_->begin();
	for (; it != this->objs_->end(); it++)
	  {
	    if ((*it)->getType() == FIRE && this->checkCollision((*it)->getPos().x, (*it)->getPos().z)  == true)
	      {
		this->explose();
		break;
	      }
	  }
	this->model_.update(gameClock);
	this->timer_.update();
	if (this->timer_.getTotalElapsedTime() >= 3)
	  this->explose();
      }
  }

  void		Bombe::draw(void)
  {
    if (this->isOver_ == false)
      {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(this->position_.x, this->position_.y, this->position_.z);
	gdl::Model::Begin();
	this->model_.draw();
	gdl::Model::End();
	glPopMatrix();
      }
  }

}
