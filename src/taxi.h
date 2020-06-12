
// #include <vector>

class Taxi
{
public:
    Taxi();
    virtual ~Taxi(){};
    std::string call(std::string input_file_path);
    unsigned int calculate();
    bool analysisInputText(std::string input_text);
    inline std::string getResult() { return m_result; };

private:
    unsigned int m_distance; //  Units of measurement: "km"
    unsigned int m_waittime; //  Units of measurement: "minute"
    std::string m_result;
};