Dopustio sam koriscenje minimalnog broja funkcija koje su vam potrebne, ostale
su skrivene kao deo implementacije... Dopustene funkcije su:
    std::pair<double, double> getV0Range()
      ovu funkciju bi trebalo pozvati pri kreiranju slajdera za brzinu, povratna
      vrednost je leva (0.8*v_circ) i desna (1.2*v_esc) granica dopustenog opsega
      brzina. Po potrebi, te granice mozemo prosiriti u sledecoj iteraciji.
    
    Integrator getIntegrator(double, double)
      vraca objekat koji je potrebno prosledjivati funckiji koja menja poziciju.
      Objekat je funkcija koja se koristi pri integraljenju i zavisi od izabrane
      pocetne brzine, i ugla koji cemo dozvoliti da bude u opsegu 
      [0, 90] stepeni. Ovu funkciju je potrebno ponovo pozvati SAMO pri resetovanju
      animacije (ali ostale funkcije ne garantuju da je to ponasanje dopusteno) te
      ako budemo dopustili resetovanje animacije u nekoj sledecoj iteraciji, moracu
      da doradim funkcije.
    
    void translatePos(double&, double&, Integrator)
      uzima reference na trenutne koordinate (x,y) sa ekrana i u iste upisuje
      koordinate naredne pozicije.

    double energy(double, double)
      novina u odnosu na prethodno, ova funkcija je cisto estetske prirode (ako
      budemo prikazivali energiju) i ne moze se koristiti kao uslov zaustavljanja
      jer iskljucivo za brzinu v0 = v_circ je orbita dovoljno stabilna da animacija
      ne pukne prerano. Razne literature koje sam citao dopustaju skokove u energiji
      ili uopste ne prate promene energije kako bi razlicite orbite uopste bile
      moguce.

    bool collision(double, double)
      konacno, novi uslov za zaustavljanje nam moze biti kombinacija duzine trajanja animacije
      i ove funkcije. Vraca true ukoliko je norma vektora pozicije komete <= sunR.

NAPOMENA: trenutna duzina vremenskog koraka dt je 1minut zbog potreba debagovanja, ukoliko nam je to
          prekratko (a moze biti zbog refresh rate ekrana) povecacemo korak do 1 dana.
