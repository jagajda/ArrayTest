#pragma once
#include <memory>
#include <stdexcept>
template <class T>
	class ArrayCorrect
	{
	private:
		std::unique_ptr<T> m_pData;
		unsigned int m_nSize;
	public:
		ArrayCorrect(unsigned int nSize = 0) : m_nSize(nSize), m_pData(m_nSize ? std::unique_ptr<T[m_nSize]> : nullptr)
		{}

		ArrayCorrect(const ArrayCorrect& other):
			m_nSize(other.m_nSize),
			m_pData(m_nSize ? std::unique_ptr<T[m_nSize]>:nullptr)
		{
			if (m_nSize)
			{
				std::copy(other.begin(), other.end(), begin());
			}
		}

		ArrayCorrect(const ArrayCorrect&& other) noexcept: m_nSize(0), m_pData(nullptr)
		{
			swap(other);
		}

		ArrayCorrect& operator=(ArrayCorrect other) noexcept
		{
			return swap(other);
		}

		ArrayCorrect& operator=(ArrayCorrect&& other) noexcept
		{
			if (this != &other)
			{
				m_pData.reset();
				swap(other);
				other.m_pData = nullptr;
				other.m_nSize = 0;
				return *this;
			}
		}

		//helper for overloading operators and constructors
		ArrayCorrect& swap(ArrayCorrect& other)
		{
			std::swap(m_nSize, other.m_nSize);
			m_pData.swap(other.m_pData);
			return *this;
		}
		virtual ~ArrayCorrect() = default;
		void Set(unsigned int nPos, const T& value) throw(std::out_of_range)
		{
			if (nPos < m_nSize)
			{
				m_pData[nPos] = value;
			}
			else
			{
				throw std::out_of_range;
			}
		}
		T Get(unsigned int nPos) throw(std::out_of_range)
		{
			if (nPos < m_nSize)
			{
				return m_pData[nPos];
			}
			else
			{
				throw std::out_of_range;			
			}
		}
		T* begin() { return m_pData.get();}
		T* end() { return begin() + m_nSize; }
		T* const* begin() const { return m_pData.get(); }
		T* const* begin() const { return begin() + mSize(); }
	};

