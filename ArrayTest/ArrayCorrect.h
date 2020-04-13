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
		ArrayCorrect(unsigned int nSize = 0) : m_nSize(nSize)
		{
			m_pData = std::make_unique<T[]>(m_nSize);
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
	};

