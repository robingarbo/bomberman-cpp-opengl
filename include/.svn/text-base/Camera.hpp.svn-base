//
// Camera.hpp for bomberman in /home/chen_b//BOMBERMAN/GDL
// 
// Made by laurent chen
// Login   <chen_b@epitech.net>
// 
// Started on  Thu May 26 16:00:09 2011 laurent chen
// Last update Sun Jun  5 21:13:48 2011 luc ngauv
//

#ifndef		__CAMERA_HPP__
# define	__CAMERA_HPP__

#  include <list>

#  include "GameClock.hpp"
#  include "Input.hpp"
#  include "Vector3.hpp"
#  include "AObject.hpp"

namespace	Perso
{
  class		Personnage;
}

class	Camera
{
public:
  Camera(void);
  void initialize(std::list<AObject *> *, bool);
  void ini_menu(void);
  void update(gdl::GameClock const &, gdl::Input &);

  Vector3f getPos(void) const;
  Vector3f getRot(void) const;
  void	   setPosition_(Vector3f npos);

private:
  Vector3f position_;
  Vector3f rotation_;
  bool			follow_;
  std::list<AObject *>	*list_;
  AObject		*player_;

  AObject		*catchPlayer(void);
};

#endif	// !__CAMERA_HPP__
