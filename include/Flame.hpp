//
// Flame.hpp for bomberman in /u/epitech_2014/el-out_y/public/bomberman/chen_b
// 
// Made by laurent chen
// Login   <chen_b@epitech.net>
// 
// Started on  Wed Jun  1 13:20:17 2011 laurent chen
// Last update Sun Jun  5 22:27:11 2011 luc ngauv
//

#ifndef			__FLAME_HPP__
# define		__FLAME_HPP__

# include		<list>
# include		<Clock.hpp>
# include		<Image.hpp>

# include		"Camera.hpp"
# include		"AObject.hpp"
# include		"Bomb.hpp"

enum			e_direction
  {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3
  };

class			Flame : public AObject
{
private :
  std::list<AObject*>	*objs_;
  bool			isExpand_;
  int			power_;
  Camera		camera_;
  e_direction		dir_;
  gdl::Image		texture_;
  gdl::Clock		timer_;

  Flame(void);
  Flame(Flame const &);
  Flame&		operator=(Flame const &);
  void			destroyObjects(void);
  void			createBonus(void);

public :
  Flame(float const, float const, int const, e_direction const, Camera const &,	std::list<AObject*> *, gdl::Image const &);
  ~Flame(void);

  void			initialize(void);
  void			update(gdl::GameClock const &, gdl::Input &);
  void			expand(void);
  void			draw(void);
  int			getPower_(void) const;
  e_direction		getDir_(void) const;
  void			setPower_(int);
  void			setDir_(e_direction);

};

#endif			// !__FLAME_HPP__
