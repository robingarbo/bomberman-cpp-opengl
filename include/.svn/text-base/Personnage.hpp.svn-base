//
// Personnage.hpp for Bomberman in /u/all/el-out_y/public/bomberman/chen_b
// 
// Made by laurent chen
// Login   <chen_b@epitech.net>
// 
// Started on  Thu May 26 19:30:18 2011 laurent chen
// Last update Sun Jun  5 22:49:05 2011 youssef el-outmani
//

#ifndef			__PERSONNAGE__
# define		__PERSONNAGE__

# include		<list>
# include		"Camera.hpp"
# include		"Model.hpp"
# include		"AObject.hpp"
# include		"Bonus.hpp"
# include		<Image.hpp>

namespace		Perso
{
  enum			e_direction
    {
      UP = 0,
      RIGHT = 1,
      DOWN = 2,
      LEFT = 3,
      BOMB = 4
    };

  struct		t_dir
  {
    e_direction		dir;
    gdl::Keys::Key	key;
    int			angle;
  };

  struct		t_mvt
  {
    e_direction		dir;
    int			coefX;
    int			coefZ;
    e_direction		rev;
  };

  class			Personnage : public AObject
  {
  private :
    Camera		camera_;
    bool		isRunning_;
    bool		isPush_;
    float		posX_;
    float		posZ_;
    int			id_;
    int			speed_;
    int			power_;
    int			nbomb_;
    int			nbombMax_;
    int			speedMax_;
    e_direction		direction_;
    gdl::Color		color_;
    gdl::Image		iFire_;
    gdl::Model		model_;
    std::list<AObject*>	*objects_;

    Personnage(void);
    Personnage(Personnage const &);
    Personnage&		operator=(Personnage const &);
    void		changeDir(void);
    void		moveIa(void);

  public :
    Personnage(gdl::Color &, float, float, int, Camera const &, std::list<AObject*> *, gdl::Image const &);
    ~Personnage(void);

    void		move(e_direction);
    void		rotate(e_direction);
    void		initialize(void);
    void		update(gdl::GameClock const &, gdl::Input &);
    void		draw(void);
    void		check_move(gdl::Input & input);
    void		check_bomb(gdl::Input & input);
    void		add_bonus(Bonus *);
    t_dir*		getKeys(void);
    int			getId_(void) const;
    int			getSpeed_(void) const;
    int			getPower_(void) const;
    int			getNbomb_(void) const;
    int			getNbombMax_(void) const;
    bool		getIsRunning_(void) const;
    e_direction		getDirection_(void) const;
    int			getSpeedMax_(void) const;
    gdl::Color		getColor_(void) const;
    void		setColor_(gdl::Color &);
    void		setSpeed_(int);
    void		setPower_(int);
    void		setNbomb_(int);
    void		setNbombMax_(int);
    void		setDirection_(e_direction);
    void		setIsRunning_(bool);
  };
}

#endif
