	#include<stdexcept>

	#include <iostream>
	template <typename T>

	class vector {
	public:
		typedef T&& rvalue;
		typedef T value_type;
		typedef T& reference;
		typedef const T& const_reference ;
		typedef std::size_t size_type;
		typedef T* pointer;
		typedef T* iterator;
		typedef const T* const_iterator;
	private:
		pointer elem_;
		size_type size_;
		size_type capacity_;

	public:

		//konstruktoriai
		vector() : size_{0}, capacity_{0}, elem_{nullptr} {}
		vector(size_type s, value_type val) {
			if (s < 0) throw std::out_of_range {"class vector cannot contain negative amount of values"};
			size_ = s;
			capacity_ = size_;
			elem_ = new value_type[capacity_];

			std::fill_n(elem_, s, val);
		}
		vector(const vector& vec) :
			size_{vec.size_},
			capacity_{vec.size_},
			elem_{new value_type[vec.size_]}
		{
			for (int i = 0; i != size_; ++i)
				elem_[i] = vec.elem_[i];
		}
		vector(std::initializer_list<value_type> il) :
			size_{il.size()},
			capacity_{il.size()},
			elem_{new value_type[il.size()]}
		{
			std::copy(il.begin(), il.end(), elem_);
		}
		vector(vector&& vec) :
			size_{vec.size_},
			capacity_{vec.size_},
			elem_{vec.elem_}
		{
			vec.elem_ = nullptr;
			vec.size_ = 0;
			vec.capacity_ = 0;
		}
		//destruktorius

		~vector() {	delete[] elem_; }

		//getteriai
		iterator begin()
		{
			return elem_;
		}
		iterator back()
		{
			return elem[size()-1];
		}
		iterator end()
		{
			return elem_ + size_;
		}
		size_type size() const
		{
			return size_;
		}
		size_type capacity()
		{
			return capacity_;
		}
		size_type size()
		{
			return size_;
		}

	//OPERATORIAI

		reference operator[](size_type a)
		{
			if (a > size_ or a < 0) throw std::out_of_range {"ref operator []"};
			return elem_[a];
		}
		const_reference operator[](size_type i) const
		{
			if (i < 0 or capacity() <= i)
				throw std::out_of_range{"const ref operator []"};
			return elem_[i];
		}
		//move
		vector<value_type>& operator=(vector&& v)
		{
			if (&v == this)
				return *this;
			delete[] elem_;
			elem_ = v.elem_;
			capacity_ = size_;
			size_ = v.size_;
			v.elem_ = nullptr;
			v.capacity_ = 0;
			v.size_ = 0;
			return *this;
		}
	//copy assigment
		vector<value_type>& operator=(const vector& v) {
			if (&v == this) return *this;
			delete[] elem_;
			elem_ = new value_type[v.size_];
			for (auto i = 0; i != v.size_; ++i)
				elem_[i] = v.elem_[i];
			capacity_ = v.capacity_;
			size_ = v.size_;

			return *this;
		}

		void resize(size_type rsize)
		{
			if (rsize < 0) throw std::out_of_range {"in function vector::resize"};
			if (rsize < size_)
			{
				pointer temp;
				temp = new value_type[rsize];
				for (auto i = 0; i < rsize; i++)
				{
					temp[i] = elem_[i];
				}
				elem_ = temp;
				temp = nullptr;
				size_ = rsize;

			} else if (rsize == capacity_)
			{
				pointer temp;
				temp = new value_type[rsize];
				for (auto i = 0; i < size_; i++)
				{
					temp[i] = elem_[i];
				}
				size_ = rsize;
				delete [] elem_;
				elem_ = temp;
				temp = nullptr;
			}
			if (rsize > capacity_)
			{
				reserve(capacity_);
				pointer temp;
				temp = new value_type[rsize];
				for (auto i = 0; i < size_; i++)
				{
					temp[i] = elem_[i];
				}
				for (auto i = size_; i < capacity_; i++)
				{
					temp[i] = value_type();
				}
				size_ = rsize;
				delete [] elem_;
				elem_ = temp;
				temp = nullptr;

			}
		}
		iterator erase(iterator pointer)
		{
			size_type del;
			for (size_type i = 0; i < size_; ++i)
			{
				if (&elem_[i] == pointer)
					del = i;


			}
			for (size_type i = del; i < size_; i++)
			{
				elem_[i] = elem_[i + 1];
			}
			elem_[size_].~value_type();
			size_ = size_ - 1;
			return &elem_[del];
		}
		iterator erase(iterator start, iterator end)
		{
			size_type st;
			size_type en;
			for (size_type i = 0; i < size_; ++i)
			{
				if (&elem_[i] == start)
				{
					st = i;

				}
				if (&elem_[i] == end - 1)
				{
					en = i;


				}

			}
			if (en > size_) throw std::out_of_range("out of range erasing");
			for (size_type i = st; i <= en; i++)
			{
				int z = 1;
				if (en + z < size_) {
					elem_[i] = elem_[en + z];
					elem_[en + z].~value_type();
				} else elem_[i].~value_type();
				z++;
			}
			size_ = size_ - (en - st +1);
			return &elem_[size_-1];
		}
		void reserve(size_type rcapacity)
		{
			if (capacity_ < rcapacity)
			{
				capacity_ = rcapacity;
				value_type *temp = new value_type[capacity_];

				for (auto i = 0; i < size_; i++)
				{
					temp[i] = elem_[i];
				}
				delete[] elem_;
				elem_ = temp;
				temp = nullptr;
			}
		}
		void push_back(const_reference value)
		{

			if (capacity_ == 0)
			{
				capacity_++;
				size_++;
				elem_ = new value_type[size_];
				elem_[0] = value;
			}
			else
			{
				if (size_ >= capacity_)
					reserve(capacity_ * 2);
				elem_[size_++] = value;
			}

		}
		void push_back(rvalue value)

		{
			if (capacity_ == 0)
			{
				capacity_++;
				size_++;
				elem_ = new value_type[size_];
				elem_[0] = value;

			}
			else
			{
				if (size_ >= capacity_)
					reserve(capacity_ * 2);

				elem_[size_++] = value;
			}

		}
		void pop_back()
		{
			if (size_ == 0) throw std::out_of_range {"pop_back"};
			elem_[size_ - 1].~value_type();
			size_--;
		}
		void shrink_to_fit()
		{
			if (capacity_ > size_)
			{
				value_type *tmp = new value_type[size_];
				for (auto i = 0; i < size_; i++)
				{
					tmp[i] = elem_[i];
				}
				delete[] elem_;
				elem_ = tmp;
				tmp = nullptr;
				capacity_ = size_;
			}
		}
		template <typename... Ts>
		void emplace_back(Ts &&... args)
		{
			push_back(value_type(std::forward<Ts>(args)...));
		}

	};