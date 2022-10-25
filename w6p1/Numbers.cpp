#define _CRT_SECURE_NO_WARNINGS

#include "Numbers.h"
#include <cstring>
#include <string>

using namespace std;

namespace sdds {

    Numbers::Numbers() {
        setEmpty();
        m_isOriginal = false;
    }

    Numbers::Numbers(const char* filename) {
        setEmpty();
        m_isOriginal = true;
        setFilename(filename);
        m_numCount = numberCount();
        if (m_numCount == 0 || !load()) {
            deallocate();
            setEmpty();
            m_isOriginal = false;
        }
    }

    Numbers::~Numbers() {
        save();
        deallocate();
    }

    bool Numbers::isEmpty() const {
        return m_numbers == nullptr;
    }

    void Numbers::setEmpty() {
        m_numbers = nullptr;
        m_filename = nullptr;
        m_numCount = 0;
    }

    void Numbers::deallocate() {
        delete[] m_filename;
        delete[] m_numbers;
    }

    void Numbers::setFilename(const char* filename) {
        delete[] m_filename;
        m_filename = new char[strlen(filename) + 1];
        strcpy(m_filename, filename);
    }

    double Numbers::average() const {
        double aver = 0.0;
        if (!isEmpty()) {
            for (int i = 0; i < m_numCount; i++)
                aver += m_numbers[i];
            aver = aver / m_numCount;
        }
        return aver;
    }

    double Numbers::min() const {
        double minVal = 0.0;
        if (!isEmpty()) {
            minVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (minVal > m_numbers[i]) minVal = m_numbers[i];
        }
        return minVal;
    }

    double Numbers::max() const {
        double maxVal = 0.0;
        if (!isEmpty()) {
            maxVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
        }
        return maxVal;
    }

    Numbers& Numbers::sort(bool ascending)
    {
        int i, j, minIdx;
        double temp;

        if (ascending)
        {
            for (i = 0; i < this->m_numCount; i++)
            {
                minIdx = i;

                for (j = i + 1; j < this->m_numCount; j++)
                {
                    if (this->m_numbers[j] < this->m_numbers[minIdx])
                    {
                        minIdx = j;
                    }
                }

                if (minIdx != i)
                {
                    temp = this->m_numbers[i];
                    this->m_numbers[i] = this->m_numbers[minIdx];
                    this->m_numbers[minIdx] = temp;
                }
            }
        }
        else
        {
            for (i = 0; i < this->m_numCount; i++)
            {
                minIdx = i;

                for (j = i + 1; j < this->m_numCount; j++)
                {
                    if (this->m_numbers[j] > this->m_numbers[minIdx])
                    {
                        minIdx = j;
                    }
                }

                if (minIdx != i)
                {
                    temp = this->m_numbers[i];
                    this->m_numbers[i] = this->m_numbers[minIdx];
                    this->m_numbers[minIdx] = temp;
                }
            }
        }

        return *this;
    }

    Numbers::Numbers(const Numbers& N)
    {
        Numbers::isEmpty();
        this->m_isOriginal = false;
        *this = N;
    }

    Numbers& Numbers::operator=(const Numbers& num)
    {
        delete[] this->m_numbers;
        Numbers::isEmpty();
        this->m_isOriginal = false;
        this->m_numbers = new double[num.m_numCount];
        for (int i = 0; i < num.m_numCount; i++)
        {
            this->m_numbers[i] = num.m_numbers[i];
        }

        return *this;
    }

    Numbers Numbers::operator-() const
    {
        Numbers temp(*this);
        temp = temp.sort(false);

        return temp;
    }

    Numbers Numbers::operator+() const
    {
        Numbers temp(*this);
        temp = temp.sort(true);

        return temp;
    }

    int Numbers::numberCount() const
    {
        int numCount = 0;
        string line;
        ifstream fptr;
        fptr.open(m_filename);
        if (fptr.is_open())
        {
            while (getline(fptr, line))
            {
                numCount++;
            }
        }
        fptr.close();

        return numCount;
    }

    bool Numbers::load()
    {
        int i = 0;
        bool istrue = false, check = false;
        ifstream fptr;
        if (this->m_numCount > 0)
        {
            this->m_numbers = new double[this->m_numCount];

            fptr.open(this->m_filename);

            if (fptr.is_open())
            {
                while (!fptr.eof() && istrue)
                {
                    if (fptr >> this->m_numbers[i])
                    {
                        istrue = true;
                        i += 1;
                    }
                }
            }
        }
        if (i == this->m_numCount)
            check = true;

        return check;
    }

    void Numbers::save()
    {
        if (this->m_isOriginal && !(Numbers::isEmpty()))
        {
            int i = 0;
            ofstream fptr;
            fptr.open(this->m_filename);
            if (fptr.is_open())
            {
                for (i = 0; i < this->m_numCount; i++)
                {
                    fptr << this->m_numbers[i] << endl;
                }
            }
        }
    }

    Numbers& Numbers::operator+=(double num)
    {
        double* temp;
        if (!isEmpty())
        {
            temp = new double[this->m_numCount + 1];
            for (int i = 0; i < this->m_numCount; i++)
            {
                temp[i] = this->m_numbers[i];
            }
            temp[this->m_numCount++] = num;
            this->m_numbers = temp;
        }

        return *this;
    }

    /*ostream& Numbers::display(ostream& ostr) const 
    {
        double avg = 0.0;
        int i = 0;
        if (isEmpty()) {
            ostr << "Empty list" << endl;
        }
        else {
            ostr << "=========================" << endl;
            if (m_isOriginal)
                ostr << m_filename << endl;
            else
                ostr << "*** COPY ***" << endl;

            ostr << m_numbers[0];
            avg += m_numbers[0];
            for (i = 1; i < m_numCount; i++)
            {
                ostr << ", " << m_numbers[i];
                avg += m_numbers[i];
            }
            ostr << endl << "-------------------------" << endl;
            ostr << "Total of " << m_numCount << " number(s)" << endl;
            ostr << "Largest number: " << -this->m_numbers[0] << endl;
            ostr << "Smallest number: " << +this->m_numbers[0] << endl;
            ostr << "Average : " << avg << endl;
            ostr << "=========================";
        }
        return ostr;
    }*/
};
