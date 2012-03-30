//
// bomber.hpp for bomberman in /home/chen_b//BOMBERMAN/GDL
// 
// Made by laurent chen
// Login   <chen_b@epitech.net>
// 
// Started on  Thu May 26 14:27:09 2011 laurent chen
// Last update Sun Jun  5 22:14:11 2011 luc ngauv
//

#ifndef		__MYGAME_HPP__
# define	__MYGAME_HPP__

#  include <cstdlib>
#  include <list>
#  include <vector>
#  include <string>
#  include <Model.hpp>

#  include "Color.hpp"
#  include "Game.hpp"
#  include "Camera.hpp"
#  include "AObject.hpp"
#  include "Map.hpp"
#  include "Image.hpp"

enum {
  MENU = 1,
  JEU,
  PAUSE
};


class		MyGame : public gdl::Game
{
public:
  void		initialize(void);
  void		pushNothing(int);
  void		update(void);
  void		draw(void);
  void		unload(void);
  void		setAObject(AObject *obj);
  void 		add(AObject *);
  Camera       	getCamera() const;
  void	       	setCamera(Camera const &);
  void 		setCameraPos(Vector3f const &t);
  void		parse_pause();
  void 		parse_menu();

private:
  Camera	camera_;
  std::list<AObject*> *objects_;
  int			state;
  int			touch;
  int			map_unit;
  int			map_diz;
  //  int			map_cent;
  int			players;
  unsigned int		ia_unit;
  unsigned int 		ia_diz;
  int			nb_ia;
  std::vector<std::string> map_name;
  int			map_size;
  std::map<std::string, gdl::Image> texture_;
  std::vector<std::string> menuselect;
};


#endif	// !__MYGAME_HPP__
