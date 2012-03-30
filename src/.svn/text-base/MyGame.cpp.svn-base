//
// bomber.cpp for bomberman in /home/chen_b//BOMBERMAN/GDL
// 
// Made by laurent chen
// Login   <chen_b@epitech.net>
// 
// Started on  Thu May 26 14:31:23 2011 laurent chen
// Last update Sun Jun  5 23:40:22 2011 luc ngauv
//

#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <map>

#include "MyGame.hpp"
#include "Floor.hpp"
#include "Wall.hpp"
#include "Personnage.hpp"
#include "Image.hpp"

void MyGame::pushNothing(int i)
{
  int		x;

  x = 0;
  while (x < i)
    {
      this->menuselect.push_back("RIEN");
      x++;
    }
}

void MyGame::initialize(void)
{
  this->map_name.push_back("map/map01");
  this->map_name.push_back("map/map02");
  this->map_name.push_back("map/map03");
  this->map_name.push_back("map/map04");
  this->map_name.push_back("map/map05");
  this->map_name.push_back("map/map06");
  this->map_name.push_back("map/map07");
  this->map_name.push_back("map/map08");
  this->map_name.push_back("map/map09");
  this->map_name.push_back("map/map10");
  this->menuselect.push_back("./assets/menu_file/Menu_1/Menu_play1.jpg");
  this->menuselect.push_back("./assets/menu_file/Menu_1/Menu_play2.jpg");
  this->menuselect.push_back("./assets/menu_file/Menu_1/Menu_load.jpg");
  this->menuselect.push_back("./assets/menu_file/Menu_1/Menu_opt.jpg");
  this->menuselect.push_back("./assets/menu_file/Menu_1/Menu_score.jpg");
  this->menuselect.push_back("./assets/menu_file/Menu_1/Menu_leave.jpg");
  pushNothing(3);
  this->menuselect.push_back("./assets/menu_file/Map/Map_size.jpg");
  pushNothing(2);
  this->menuselect.push_back("./assets/menu_file/Pause/Pause_resum.jpg");
  this->menuselect.push_back("./assets/menu_file/Pause/Pause_save.jpg");
  this->menuselect.push_back("./assets/menu_file/Pause/Pause_opt.jpg");
  this->menuselect.push_back("./assets/menu_file/Pause/Pause_leave.jpg");
  pushNothing(1);
  this->menuselect.push_back("./assets/menu_file/sc_opt/Opt.jpg");
  pushNothing(1);
  this->menuselect.push_back("./assets/menu_file/Map/Map_def.jpg");
  pushNothing(9);
  this->menuselect.push_back("./assets/menu_file/Menu_1/Menu_load.jpg");
  pushNothing(9);
  this->menuselect.push_back("./assets/menu_file/sc_opt/Opt.jpg");
  pushNothing(9);
  this->menuselect.push_back("./assets/menu_file/sc_opt/Score.jpg");
  pushNothing(49);
  this->menuselect.push_back("./assets/menu_file/Menu_play/Play_nbia.jpg");

  this->touch = 1;
  this->map_unit = 0;
  this->map_diz = 0;
  this->state = MENU;
  this->texture_[menuselect[12]] = gdl::Image::load(menuselect[12]);
  this->texture_["wall"] = gdl::Image::load("assets/textures/wall.png");
  this->texture_["bwall"] = gdl::Image::load("assets/textures/bwall.png");
  this->texture_["floor"] = gdl::Image::load("assets/textures/gazon.jpg");
  this->texture_["flame"] = gdl::Image::load("assets/textures/flamme.jpg");
  window_.setTitle("Bomberman");
  window_.setHeight(700);
  window_.setWidth(1024);
  this->window_.create();
  this->camera_.ini_menu();
}

void MyGame::update(void)
{
  if (this->input_.isKeyDown(gdl::Keys::Escape) && this->state == JEU)
    {
      Vector3f		t;

      t.x = 000.0f;
      t.y = 000.0f;
      t.z = 5500.0f;
      glLoadIdentity();

      this->state = PAUSE;
      this->touch = 13;
      this->texture_[menuselect[touch -1]] = gdl::Image::load(menuselect[touch - 1]);
      this->camera_.setPosition_(t);
      this->camera_.ini_menu();
    }
  else if (this->state == JEU)
    {
      std::list<AObject*>::iterator itb = this->objects_->begin();
      for (; itb != this->objects_->end(); ++itb)
	(*itb)->update(gameClock_, input_);
      camera_.update(gameClock_, input_);
      Map::deleteOverObjects(this->objects_);
    }
  else
    this->parse_menu();
}

void		MyGame::parse_menu()
{
  if (this->state == PAUSE)
    {
      if (touch > 12 && touch < 17)
	{
	  if (input_.isKeyDown(gdl::Keys::Escape) || (input_.isKeyDown(gdl::Keys::Space) && touch == 13))
	    {
	      Vector3f		t;

	      t.x = 300 * this->map_size;
	      t.y = 490 * this->map_size + 200;
	      t.z = 285 * this->map_size;

	      this->camera_.setPosition_(t);
	      this->camera_.initialize(this->objects_, true);
	      this->state = JEU;
	    }
	  else if (input_.isKeyDown(gdl::Keys::Up) || input_.isKeyDown(gdl::Keys::Down))
	    {
	      if (input_.isKeyDown(gdl::Keys::Down))
		touch++;
	      else
		touch--;
	    }
	  else if (input_.isKeyDown(gdl::Keys::Space))
	    {
	      if (touch == 16)
		{
		  window_.close();
		  exit(0);
		}
	      else if (touch == 15)
		touch = 18;
	    }
	}
      else if (touch == 18)
	{
	  if (input_.isKeyDown(gdl::Keys::Escape))
	    touch = 13;
	}
    }
  else if (touch == 100 || touch == 20)
    {
      if (touch == 20)
	{
	  unsigned int		x;
	  std::map<int, bool>	inp;
	  std::map<int, bool>::const_iterator	beg;

	  x = 0;
	  inp[0] = input_.isKeyDown(gdl::Keys::Numpad0);
	  inp[1] = input_.isKeyDown(gdl::Keys::Numpad1);
	  inp[2] = input_.isKeyDown(gdl::Keys::Numpad2);
	  inp[3] = input_.isKeyDown(gdl::Keys::Numpad3);
	  inp[4] = input_.isKeyDown(gdl::Keys::Numpad4);
	  inp[5] = input_.isKeyDown(gdl::Keys::Numpad5);
	  inp[6] = input_.isKeyDown(gdl::Keys::Numpad6);
	  inp[7] = input_.isKeyDown(gdl::Keys::Numpad7);
	  inp[8] = input_.isKeyDown(gdl::Keys::Numpad8);
	  inp[9] = input_.isKeyDown(gdl::Keys::Numpad9);

	  for (beg = inp.begin(); beg != inp.end(); beg++)
	    {
	      x++;
	      if (beg->second == true)
		{
		  if (map_unit != 0)
		    {
		      map_diz = map_unit;
		      map_unit = x - 1;
		    }
		  else
		    map_unit = x - 1;
		  break;
		}
	    }
	}
      if (touch == 20)
	{
	  this->map_size = this->map_diz * 10 + this->map_unit;
	  if (this->map_size > 10)
	    this->map_size = 10;
	  else if (this->map_size < 1)
	    this->map_size = 1;
	  Map			lol(this->map_name[this->map_size - 1], this->camera_, this->texture_);
	  this->objects_ = lol.generate();
	  this->map_size = 15;
	}
      else
	{
	  this->map_size = this->map_diz * 10 + this->map_unit;
	  Map			lol(this->map_size, 5, this->camera_, this->texture_);

	  this->objects_ = lol.generate();
	}
      if (input_.isKeyDown(gdl::Keys::Escape))
	touch = 1;
      else if (input_.isKeyDown(gdl::Keys::Space))
	{
	  Vector3f		t;

	  t.x = 300 * this->map_size;
	  t.y = 490 * this->map_size + 200;
	  t.z = 285 * this->map_size;

	  this->camera_.setPosition_(t);
	  if (touch == 20)
	    this->camera_.initialize(this->objects_, true);
	  else
	    this->camera_.initialize(this->objects_, true);
	  std::list<AObject*>::iterator itb = this->objects_->begin();
	  for (; itb != this->objects_->end(); ++itb)
	    (*itb)->initialize();
	  this->state = JEU;
	}
    }
  else
    {
      if (input_.isKeyDown(gdl::Keys::Down))
	touch++;
      else if (input_.isKeyDown(gdl::Keys::Up))
	touch--;
      else
	{
	  if (input_.isKeyDown(gdl::Keys::Escape))
	    {
	      if (touch >= 1 && touch <= 6)
		{
		  window_.close();
		  exit(0);
		}
	      else if ((touch == 10) || (touch >= 20))
		touch = touch % 10;
	    }
	  else
	    {
	      if (input_.isKeyDown(gdl::Keys::Space))
		{
		  if (touch == 6)
		    {
		      window_.close();
		      exit(0);
		    }
		  else if (touch < 12 && touch != 3)
		    {
		      if (touch == 1)
			this->players = 1;
		      else
			this->players = 2;
		      touch = touch * 10;
		    }
		}
	      else if (touch == 10)
		{
		  unsigned int		x;
		  std::map<int, bool>	inp;
		  std::map<int, bool>::const_iterator	beg;

		  x = 0;
		  inp[0] = input_.isKeyDown(gdl::Keys::Numpad0);
		  inp[1] = input_.isKeyDown(gdl::Keys::Numpad1);
		  inp[2] = input_.isKeyDown(gdl::Keys::Numpad2);
		  inp[3] = input_.isKeyDown(gdl::Keys::Numpad3);
		  inp[4] = input_.isKeyDown(gdl::Keys::Numpad4);
		  inp[5] = input_.isKeyDown(gdl::Keys::Numpad5);
		  inp[6] = input_.isKeyDown(gdl::Keys::Numpad6);
		  inp[7] = input_.isKeyDown(gdl::Keys::Numpad7);
		  inp[8] = input_.isKeyDown(gdl::Keys::Numpad8);
		  inp[9] = input_.isKeyDown(gdl::Keys::Numpad9);

		  for (beg = inp.begin(); beg != inp.end(); beg++)
		    {
		      x++;
		      if (beg->second == true)
			{
			  if (map_unit != 0)
			    {
			      map_diz = map_unit;
			      map_unit = x - 1;
			    }
			  else
			    map_unit = x - 1;
			  break;
			}
		    }
		}
	    }
	}
    }
  if (touch == 0 || touch == 9 || touch == 12 || touch == 19 || touch == 29 || touch == 39 || touch == 49 || touch == 99)
    touch++;
  else if (touch == 7 || touch == 11 || touch == 17 || touch == 21 || touch == 31 || touch == 41 || touch == 51 || touch == 101)
    touch--;
  this->texture_[menuselect[touch -1]] = gdl::Image::load(menuselect[touch - 1]);
}

void MyGame::draw(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClearDepth(1.0f);
  if (this->state == JEU)
    {
      std::list<AObject *>::iterator itb = this->objects_->begin();
      for (; itb != this->objects_->end(); ++itb)
	if((((*itb)->getPos().x < this->camera_.getPos().x + 26 * BLOCK_SIZE) &&
            ((*itb)->getPos().z < this->camera_.getPos().z + 26 * BLOCK_SIZE)) &&
           (((*itb)->getPos().x > this->camera_.getPos().x - 26 * BLOCK_SIZE) &&
            ((*itb)->getPos().z > this->camera_.getPos().z - 26 * BLOCK_SIZE)))
	  (*itb)->draw();
    }
  else
    {
      texture_[menuselect[touch - 1]].bind();
      glBegin(GL_QUADS);
      glTexCoord2f(0.0f, 0.0f);
      glVertex3f(-5000.0f, 4000.0f, 0000.0f);
      glTexCoord2f(0.0f, 1.0f);
      glVertex3f(-5000.0f, -4000.0f, 0000.0f);
      glTexCoord2f(1.0f, 1.0f);
      glVertex3f(5000.0f, -4000.0f, 0000.0f);
      glTexCoord2f(1.0f, 0.0f);
      glVertex3f(5000.0f, 4000.0f, 0000.0f);

      glEnd();
    }
  this->window_.display();
}

void		MyGame::add(AObject *obj)
{
  this->objects_->push_front(obj);
}

void MyGame::unload(void)
{
  std::list<AObject *>::iterator itb = this->objects_->begin();
  for (; itb != this->objects_->end(); itb++)
    delete *itb;
  this->objects_->clear();
}

Vector3f::Vector3f(void)
  : x(0.0f), y(0.0f), z(0.0f)
{}

Vector3f::Vector3f(float x, float y, float z)
  : x(x), y(y), z(z)
{}

void MyGame::setAObject(AObject *obj)
{
  this->objects_->push_front(obj);
}

Camera		MyGame::getCamera() const
{
  return (this->camera_);
}

void            MyGame::setCamera(Camera const &camera)
{
  this->camera_ = camera;
}

void		MyGame::setCameraPos(Vector3f const &t)
{
  this->camera_.setPosition_(t);
}


