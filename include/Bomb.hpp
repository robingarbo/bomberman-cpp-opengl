//
// Bomb.hpp for bomberman in /u/all/el-out_y/public/bomberman/chen_b
// 
// Made by laurent chen
// Login   <chen_b@epitech.net>
// 
// Started on  Tue May 31 21:47:05 2011 laurent chen
// Last update Sun Jun  5 22:25:17 2011 luc ngauv
//

#ifndef			__BOMB_HPP__
# define		__BOMB_HPP__

# include		<list>
# include		<Clock.hpp>
# include		<Model.hpp>
# include		<Image.hpp>

# include		"Personnage.hpp"
# include		"Camera.hpp"
# include		"AObject.hpp"

namespace		Bomb
{
  class			Bombe : public AObject
  {
  private :
    int			id_;
    int			power_;
    Camera		camera_;
    Perso::Personnage	*pl_;
    std::list<AObject*>	*objs_;
    gdl::Image		iFire_;
    gdl::Clock		timer_;
    gdl::Model		model_;

    Bombe(void);
    void		adjPos(void);
    Bombe(Bombe const &);
    Bombe&		operator=(Bombe const &);

  public :
    Bombe(float const, float const, int const, int const, Camera const &, Perso::Personnage *, std::list<AObject*> *, gdl::Image const &);
    ~Bombe(void);

    void		initialize(void);
    void		update(gdl::GameClock const &, gdl::Input &);
    void		draw(void);
    void		explose(void);
    int			getPower_(void) const;
    int			getId_(void) const;
    void		setId_(int);
    void		setPower_(int);
  };
}

#endif	// !__BOMB_HPP__
