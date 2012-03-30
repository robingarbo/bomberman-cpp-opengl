//
// BreakableWall.hpp for  in /u/all/el-out_y/public/bomberman/garbo_r
// 
// Made by mickael mendel
// Login   <mendel_m@epitech.net>
// 
// Started on  Sun May 29 14:10:17 2011 mickael mendel
// Last update Sun Jun  5 18:23:15 2011 luc ngauv
//

#ifndef BREAKABLEWALL_HPP_
# define BREAKABLEWALL_HPP_

#  include	<Image.hpp>
#  include	"Game.hpp"
#  include	"Vector3.hpp"
#  include	"Wall.hpp"
#  include	"Camera.hpp"

class		BreakableWall : public Wall
{
private:
  bool		broken_;
  int		bonus_;

  BreakableWall();
  BreakableWall(BreakableWall const &);
  BreakableWall		&operator=(BreakableWall const &);

public:
  BreakableWall(int const, int const, int const, Camera const &, gdl::Image const &);
  ~BreakableWall(){};

  bool		isBroken(void) const;
  int		getBonus(void) const;

  void		initialize(void);
  void		draw();
  void		update(gdl::GameClock const &, gdl::Input &);
};

#endif
