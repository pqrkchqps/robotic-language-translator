#include "parseResult.h"

template <class A>
class FunctionalResult : public ParseResult {
public:
    FunctionalResult(std::string type, std::string name){
	this->setErrors("");
	this->setOK(true) ;
	this->ast = new A();
	this->type = type;
	this->name = name;
    	this->value = "NULL";
    };

    FunctionalResult(std::string type, std::string name, std::string value){
	this->setErrors("");
	this->setOK(true) ;
	this->ast = new A();
	this->type = type;
	this->name = name;
    	this->value = value;
    };

    ~FunctionalResult() {};
    std::string getType() {return this->type;};
    std::string getName() {return this->name;};
    std::string getValue() {return this->value;};

private:
    std::string type;
    std::string name;
    std::string value;
};

class ConsFunctionalResult : public ParseResult{
public:
    ConsFunctionalResult(ParseResult car, ParseResult cdr);
    ~ConsFunctionalResult() {};

    ParseResult car() {
    	return this->left;
    };

    ParseResult cdr() {
    	return this->right;
    };
private:
    ParseResult left;
    ParseResult right;
};

class NullFunctionalResult : public ParseResult{
public:
    NullFunctionalResult();
    ~NullFunctionalResult() {};
};
