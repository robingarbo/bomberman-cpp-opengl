//
// Floor.hpp for  in /u/all/el-out_y/public/bomberman/garbo_r
// 
// Made by mickael mendel
// Login   <mendel_m@epitech.net>
// 
// Started on  Sun May 29 14:34:35 2011 mickael mendel
// Last update Sun Jun  5 18:24:48 2011 luc ngauv
//

#ifndef FLOOR_HPP_
# define FLOOR_HPP_

#  include	<Image.hpp>
#  include	"AObject.hpp"
#  include	"Camera.hpp"

class Floor : public AObject
{
private:
  gdl::Image	texture_;
  Camera	camera;

  Floor(void);
  Floor(Floor const &);
  Floor		&operator=(Floor const &);

public:
  Floor(int const, int const, Camera const &, gdl::Image const &);
  ~Floor(void) {};
  void initialize(void);
  void update(gdl::GameClock const &, gdl::Input &);
  void draw(void);
};

#endif
