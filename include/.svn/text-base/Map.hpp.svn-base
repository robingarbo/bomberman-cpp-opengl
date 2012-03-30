//
// map.hpp for ok in /u/all/el-out_y/public/bomberman/garbo_r
// 
// Made by robin garbo
// Login   <garbo_r@epitech.net>
// 
// Started on  Sat May 28 17:48:58 2011 robin garbo
// Last update Sun Jun  5 21:33:02 2011 youssef el-outmani
//


#ifndef		__MAP_HPP__
# define	__MAP_HPP__

#  include	<list>
#  include	<map>
#  include	<Color.hpp>
#  include	<Image.hpp>
#  include	<Model.hpp>

#  include	"Vector3.hpp"
#  include	"AObject.hpp"
#  include	"Camera.hpp"

class			Map;
typedef void (Map::*	pFunc)(int, int);

class			Map
{
private:
  std::string		filename_;
  std::list<AObject *>	*list_;
  std::map<int, pFunc>  func_;
  std::map<int, std::pair<int, int> > playersPositions_;
  Camera		camera_;
  int			id;
  std::map<std::string, gdl::Image> textures_;
  gdl::Model            perso_mod;

  Map(Map const &);
  Map			&operator=(Map const &);
  int			checkElementInMap(char c, int x);
  void			createFloor(int, int);
  void			createBwall(int, int);
  void			createUwall(int, int);
  void			createBonus(int, int);
  void			createPlayer(int, int);
  void			createPlayer(int);
  int			randmap(int);
  bool			check_error(int);
  void			setPlayers(void);
  void			checkForOpen(const int, const int);

public:
  Map(std::string const &map, Camera const &, std::map<std::string, gdl::Image> const &);
  Map(int const, int const, Camera const &, std::map<std::string, gdl::Image> const &);
  Map(void);
  ~Map(void) {};
  std::list<AObject *>	*generate(void);
  static void		deleteOverObjects(std::list<AObject *> *objects);
};

#endif		// !__MAP_HPP__
