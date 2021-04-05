#ifndef COLOR
#define COLOR

union ARGB{
	unsigned char argb[4];
	struct {
		unsigned char a;
		unsigned char r;
		unsigned char g;
		unsigned char b;
	};
	int i;

	ARGB():            i(0) {}
	ARGB(const int x): i(x) {}

	ARGB(const unsigned char r_, const unsigned char g_, const unsigned char b_, const unsigned char a_ = 255):
	a(a_),
	r(r_),
	g(g_),
	b(b_)
	{}

	ARGB(const int r_, const int g_, const int b_, const int a_ = 255):
	a((unsigned char) a_),
	r((unsigned char) r_),
	g((unsigned char) g_),
	b((unsigned char) b_)
	{}

	operator int() const;
};

inline ARGB::operator int() const { return i; }
inline ARGB mult      (const float num, const ARGB argb) { return {(unsigned char) (argb.r * num),
																   (unsigned char) (argb.g * num),
																   (unsigned char) (argb.b * num),
																   (unsigned char) (argb.a      )}; }
inline ARGB operator+(const ARGB other, const ARGB argb) { return {(unsigned char) (argb.r + other.r),
																   (unsigned char) (argb.g + other.g),
																   (unsigned char) (argb.b + other.b),
																   (unsigned char) (argb.a          )}; }

#endif // COLOR