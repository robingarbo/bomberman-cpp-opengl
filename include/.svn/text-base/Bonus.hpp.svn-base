//
// Bonus.hpp for bomberman in /home/chen_b//BOMBERMAN/chen_b
// 
// Made by laurent chen
// Login   <chen_b@epitech.net>
// 
// Started on  Thu Jun  2 20:16:41 2011 laurent chen
// Last update Sun Jun  5 00:04:44 2011 youssef el-outmani
//

#ifndef                 __BONUS_HPP__
# define                __BONUS_HPP__

# include               <list>

# include               "Clock.hpp"
# include               "Camera.hpp"
# include               "Image.hpp"
# include               "AObject.hpp"

class			Bonus : public AObject
{
private :

  Camera                camera_;
  gdl::Clock            timer_;
  gdl::Image            texture_;
  int			bType_;

public :

  Bonus(void);
  Bonus(float, float, Camera const &, int);
  Bonus(Bonus const &);
  ~Bonus(void);
  Bonus&                operator=(Bonus const &);

  void                  initialize(void);
  void                  update(gdl::GameClock const &, gdl::Input &);
  void                  draw(void);
  int			getBType_(void) const;

};

#endif			// !__BONUS_HPP__
