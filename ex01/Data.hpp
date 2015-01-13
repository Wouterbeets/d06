

struct Data {
		std::string			s1;
		int					n;
		std::string			s2;
		Data();
		~Data();
		Data(std::string s1, int n, str::string s2);
	private:
		Data(Data const & src);
		Data  &	operator=(Data const & d);
}

void *serialize(void *ser);
Data *deserialize(void *ser);

