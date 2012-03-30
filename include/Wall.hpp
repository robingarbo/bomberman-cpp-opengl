//
// wall.hpp for ok in /u/all/el-out_y/public/bomberman/garbo_r
// 
// Made by robin garbo
// Login   <garbo_r@epitech.net>
// 
// Started on  Sat May 28 17:57:17 2011 robin garbo
// Last update Sun Jun  5 18:39:20 2011 luc ngauv
//

#ifndef		__WALL_HPP__

# define	__WALL_HPP__

#  include	<Image.hpp>
#  include	"Game.hpp"
#  include	"Vector3.hpp"
#  include	"AObject.hpp"
#  include	"Camera.hpp"

class		Wall : public AObject
{
private:
  Wall();
  Wall(Wall const &);
  Wall		&operator=(Wall const &);

protected:
  gdl::Image	texture_;
  Camera	camera;

public:
  Wall(int const, int const, Camera const &, gdl::Image const &);
  virtual ~Wall(){};

  virtual void	initialize(void);
  virtual void	draw();
  virtual void	update(gdl::GameClock const &, gdl::Input &);
};

#endif // !__WALL_HPP__
