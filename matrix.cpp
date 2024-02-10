class CPPMatrix {
  private:
    int *m_data;
    unsigned int m_rows;
    unsigned int m_columns;

  public:
    CPPMatrix(unsigned int rows, unsigned int columns) {
        m_rows = rows;
        m_columns = columns;
        m_data = new int[rows * columns];
    }

    ~CPPMatrix() { delete[] m_data; }
};