template < typename T, typename Allocator = std::allocator<T> >

template < typename T, typename Allocator = std::allocator<T> >

class vector
{
private :
	// データメンバー
public :
	// value_typeなどネストされた型名
	using value_type = T ;
	// コンストラクター
	vector( std::size_t n = 0, Allocator a = Allocator() ) ;
	// デストラクター
	~vector() ;
	// コピー
	vector( const vector & x ) ;
	vector & operator =( const vector & x ) ;

	// 要素アクセス
	void push_back( const T & x ) ;
	T & operator []( std::size_t i ) noexcept ;

	// イテレーターアクセス
	iterator begin() noexcept ;
	iterator end() noexcept ;
} ;