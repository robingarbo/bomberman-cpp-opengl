//
// AObject.hpp for bomberman in /home/chen_b//BOMBERMAN/GDL
// 
// Made by laurent chen
// Login   <chen_b@epitech.net>
// 
// Started on  Thu May 26 16:05:52 2011 laurent chen
// Last update Sat Jun  4 23:18:45 2011 robin garbo
//

#ifndef		__AOBJECT_HPP__
# define	__AOBJECT_HPP__

#  include	"Game.hpp"
#  include	"Vector3.hpp"

#  define	BLOCK_SIZE	300

enum {
  FLOOR = 1,
  UBWALL,
  BWALL,
  BONUS,
  BOMB,
  FIRE,
  PLAYER,
  BONUS_BOMB,
  BONUS_SPEED,
  BONUS_FIRE
};

class		AObject
{
public:
  AObject(void);
  AObject(int);
  virtual ~AObject(void);
  virtual void	initialize(void) = 0;
  virtual void	update(gdl::GameClock const &, gdl::Input &) = 0;
  virtual void	draw(void) = 0;
  Vector3f	getPos(void) const;
  bool		checkCollision(float, float);
  Vector3f	getRot(void) const;
  int		getType(void) const;
  bool		isOver(void) const;
protected:
  Vector3f	position_;
  Vector3f	rotation_;
  int		type_;
  bool		isOver_;
};

#endif	// !__AOBJECT_HPP__
