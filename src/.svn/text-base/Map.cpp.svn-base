//
// map.cpp for ok in /u/all/el-out_y/public/bomberman/garbo_r
// 
// Made by robin garbo
// Login   <garbo_r@epitech.net>
// 
// Started on  Sat May 28 18:25:45 2011 robin garbo
// Last update Sun Jun  5 23:27:06 2011 luc ngauv
//

#include <cstdlib>
#include <iostream>
#include <istream>
#include <fstream>

#include "Map.hpp"
#include "Wall.hpp"
#include "BreakableWall.hpp"
#include "Floor.hpp"
#include "Personnage.hpp"

Map::Map(int const size, int const nb_player, Camera const &camera, std::map<std::string, gdl::Image> const &textures)
  : filename_("")
{
  this->list_ = new std::list<AObject*>;
  this->camera_ = camera;
  this->textures_ = textures;
  this->id = 1;
  if (size % 2 == 0)
    randmap(size + 1);
  else
    randmap(size);
  for (int i = 0; i <= nb_player; i++)
    createPlayer(size);
}

void		Map::checkForOpen(const int x, const int y)
{
  int		value;

  value = rand() % 2;
  if ((x % 2 == 1) || (y % 2 == 1))
    {
      this->list_->push_front(new Floor(x, y, this->camera_, this->textures_["floor"]));
      if (value == 1)
	this->list_->push_front(new BreakableWall(x, y, 0, this->camera_, this->textures_["bwall"]));
    }
}

bool		Map::check_error(int size)
{
  if (size % 2 == 0)
    return (true);
  if (size < 5)
    return (true);
  return (false);
}

int		Map::randmap(int size)
{
  int		x = 0;
  int		y = 0;

  srand (time(NULL));
  if (check_error(size) == true)
    return (-1);
  while (x != size + 1)
    {
      y = 0;
      while (y != size + 1)
	{
	  if ((y == 0 || x == 0 || x == size || y == size) ||
	      ((y % 2) == 0 && (x % 2) == 0))
	    this->list_->push_front(new Wall(x, y, this->camera_, this->textures_["wall"]));
	  else
	    checkForOpen(x, y);
	  y++;
	}
      x++;
    }
  return (0);
}

Map::Map(const std::string &filename, Camera const &camera, std::map<std::string, gdl::Image> const &textures)
  : filename_(filename), camera_(camera), textures_(textures)
{
  this->list_ = new std::list<AObject*>;
  this->id = 1;
}

std::list<AObject *> *Map::generate(void)
{
  if (this->filename_ == "")
    {
      this->setPlayers();
      std::list<AObject*>::iterator itb = this->list_->begin();
      for (; itb != this->list_->end(); ++itb)
	if ((*itb)->getType() == PLAYER && (dynamic_cast<Perso::Personnage *>(*itb))->getId_() == 2)
	  {
	    delete (*itb);
	    this->list_->erase(itb);
	    break;
	  }
      return this->list_;
    }

  std::ifstream ifs(this->filename_.c_str(), std::ifstream::in);

  if (ifs.is_open() == true)
    {
      this->func_[FLOOR] = &Map::createFloor;
      this->func_[BWALL] = &Map::createBwall;
      this->func_[UBWALL] = &Map::createUwall;
      this->func_[BONUS] = &Map::createBonus;
      this->func_[PLAYER] = &Map::createPlayer;
      int i = 0;
      while (ifs.good())
	{
	  i = checkElementInMap((char)ifs.get(), i);
	  i++;
	}
    }
  else
    std::cerr << "error to open Map" << std::endl;
  ifs.close();
  this->setPlayers();
  return this->list_;
}

void	Map::createFloor(int x, int y)
{
  this->list_->push_front(new Floor(x, y, this->camera_, this->textures_["floor"]));
}

void	Map::createBwall(int x, int y)
{
  this->createFloor(x, y);
  this->list_->push_front(new BreakableWall(x, y, 0, this->camera_, this->textures_["bwall"]));
}

void	Map::createUwall(int x, int y)
{
  this->list_->push_front(new Wall(x, y, this->camera_, this->textures_["wall"]));
}

void	Map::createBonus(int x, int y)
{
  this->list_->push_front(new Wall(x, y, this->camera_, this->textures_["wall"]));
}

void	Map::createPlayer(int size)
{
  int	x;
  int	y;

  x = (rand() % (size - 4)) + 3;
  y = (rand() % (size - 4)) + 3;
  x = (x % 2 == 0) ? (x - 1) : (x);
  y = (y % 2 == 0) ? (y - 1) : (y);

  std::list<AObject *>::iterator it = this->list_->begin();
  for (; it != this->list_->end(); ++it)
    {
      if (((*it)->getPos().x == (x * BLOCK_SIZE * 2) || ((*it)->getPos().x == ((x + 1) * BLOCK_SIZE * 2))) &&
	  ((*it)->getPos().z == (y * BLOCK_SIZE * 2) || ((*it)->getPos().z == ((y + 1) * BLOCK_SIZE * 2))) &&
	  !((*it)->getPos().x == ((x + 1) * BLOCK_SIZE * 2) && ((*it)->getPos().z == ((y + 1) * BLOCK_SIZE * 2))))
	{
	  delete *it;
	  this->list_->erase(it);
	  it = this->list_->begin();
	}
    }
  this->list_->push_back(new Floor(x, y, this->camera_, this->textures_["floor"]));
  this->list_->push_back(new Floor(x + 1, y, this->camera_, this->textures_["floor"]));
  this->list_->push_back(new Floor(x, y + 1, this->camera_, this->textures_["floor"]));
  this->createPlayer(x, y);
}

void	Map::setPlayers(void)
{
  std::map<int, std::pair<int, int> >::iterator it = this->playersPositions_.begin();
  for (; it != this->playersPositions_.end(); it++)
    {
      gdl::Color color(rand() % 255 , rand() % 255, rand() % 255);
      this->createFloor(it->second.first, it->second.second);
      Perso::Personnage *pl = new Perso::Personnage(color, it->second.first * (BLOCK_SIZE * 2), it->second.second * (BLOCK_SIZE * 2), it->first, this->camera_, (this->list_), this->textures_["flame"]);
      this->list_->push_back(pl);
    }
}

void	Map::createPlayer(int x, int y)
{
  this->playersPositions_[this->id].first = x;
  this->playersPositions_[this->id].second = y;
  this->id++;
}

int	Map::checkElementInMap(char c, int x)
{
  static int	y = 0;
  int	value = c - '0';

  if (c == '\n')
    {
      y++;
      return (-1);
    }
  if (this->func_[value])
    (this->*func_[value])(x, y);
  else if (value < FLOOR && value > PLAYER)
    {
      std::cerr << "error invalid map!" << std::endl;
      exit(EXIT_FAILURE);
    }
  return (x);
}

void	Map::deleteOverObjects(std::list<AObject *> *objects)
{
  std::list<AObject *>::iterator it = objects->begin();
  for (; it != objects->end(); it++)
    {
      if (((*it)->getType() == BOMB || (*it)->getType() == FIRE) && (*it)->isOver() == true)
	{
	  delete *it;
	  objects->erase(it);
	  break;
	}
    }
}
