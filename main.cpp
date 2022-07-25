#include <cstring>
#include "jsoncpp/include/json.h"

struct Student {
    char id[20];
    char name[10];
    int age;
    int gender;
    char major[10];
};


std::string ToJson(const Student &stu)
{
    Json::Value studentValue;
    Json::FastWriter writer;
    studentValue["id"] = stu.id;
    studentValue["name"] = stu.name;
    studentValue["age"] = stu.age;
    studentValue["gender"] = stu.gender;
    studentValue["major"] = stu.major;

    return writer.write(studentValue);
}

Student FromJson(const std::string &strJson)
{
    Json::Reader reader;
    Json::Value studentValue;
    Student stu;
    memset(&stu,0,sizeof(Student));
    if (reader.parse(strJson, studentValue)) {
        strcpy(stu.id, studentValue["id"].asString().c_str());
        strcpy(stu.name, studentValue["name"].asString().c_str());
        stu.age = studentValue["age"].asInt();
        stu.gender = studentValue["gender"].asInt();
        strcpy(stu.major, studentValue["major"].asString().c_str());
    }

    return stu;
}

int main()
{
    // 序列化
    Student stu1 = {"10001", "张三", 18, 1, "计算机"};
    std::string strStu1 = ToJson(stu1);
    printf("(studentToJson)strJson = %s", strStu1.c_str());


    // 反序列化
    // json格式，以花括号开头和结尾
    std::string strStu2 = "{\"id\":\"10002\",\"name\":\"李四\",\"age\":20,\"gender\":0,\"major\":\"英语\"}";
    Student stu2 = FromJson(strStu2);
    printf("id:%s\n"
           "name:%s\n"
           "age:%d\n"
           "gender:%d\n"
           "major:%s\n", stu2.id, stu2.name, stu2.age, stu2.gender, stu2.major);

    return 0;
}

