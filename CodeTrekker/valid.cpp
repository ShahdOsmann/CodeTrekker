﻿#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include <regex>
#include "user.h"
#include "valid.h"
#define ll long long
using namespace std;
bool validate_email(const string& email)
{
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
}
bool validate_password(const std::string& password) {
    // At least 8 characters
    if (password.length() < 8) {
        return false;
    }
    // At least one uppercase letter
    if (!std::regex_search(password, std::regex("[A-Z]"))) {
        return false;
    }
    // At least one lowercase letter
    if (!std::regex_search(password, std::regex("[a-z]"))) {
        return false;
    }
    // At least one digit
    if (!std::regex_search(password, std::regex("[0-9]"))) {
        return false;
    }
    // At least one special character
    if (!std::regex_search(password, std::regex("[!@#$%^&*()-_=+{};:,<.>]"))) {
        return false;
    }
    return true;
}

bool validate_handle(string handle)
{
    for (int i = 0; i < handle.size(); i++)
    {
        if ((handle[i] >= 48 && handle[i] <= 59) || (handle[i] >= 65 && handle[i] <= 90) || (handle[i] >= 97 && handle[i] <= 122)
            || handle[i] == '-' || handle[i] == '.' || handle[i] == '-')continue;
        else return 0;
    }
    return 1;
}

std::map<std::string, bool> countryNames = {
    {"afghanistan", true},
    {"åland islands", true},
    {"albania", true},
    {"algeria", true},
    {"american samoa", true},
    {"andorra", true},
    {"angola", true},
    {"anguilla", true},
    {"antarctica", true},
    {"antigua and barbuda", true},
    {"argentina", true},
    {"armenia", true},
    {"aruba", true},
    {"australia", true},
    {"austria", true},
    {"azerbaijan", true},
    {"bahamas", true},
    {"bahrain", true},
    {"bangladesh", true},
    {"barbados", true},
    {"belarus", true},
    {"belgium", true},
    {"belize", true},
    {"benin", true},
    {"bermuda", true},
    {"bhutan", true},
    {"bolivia (plurinational state of)", true},
    {"bonaire, sint eustatius and saba", true},
    {"bosnia and herzegovina", true},
    {"botswana", true},
    {"bouvet island", true},
    {"brazil", true},
    {"british indian ocean territory", true},
    {"brunei darussalam", true},
    {"bulgaria", true},
    {"burkina faso", true},
    {"burundi", true},
    {"cabo verde", true},
    {"cambodia", true},
    {"cameroon", true},
    {"canada", true},
    {"cayman islands", true},
    {"central african republic", true},
    {"chad", true},
    {"chile", true},
    {"china", true},
    {"christmas island", true},
    {"cocos (keeling) islands", true},
    {"colombia", true},
    {"comoros", true},
    {"congo", true},
    {"congo (democratic republic of the)", true},
    {"cook islands", true},
    {"costa rica", true},
    {"côte d'ivoire", true},
    {"croatia", true},
    {"cuba", true},
    {"curaçao", true},
    {"cyprus", true},
    {"czech republic", true},
    {"denmark", true},
    {"djibouti", true},
    {"dominica", true},
    {"dominican republic", true},
    {"ecuador", true},
    {"egypt", true},
    {"el salvador", true},
    {"equatorial guinea", true},
    {"eritrea", true},
    {"estonia", true},
    {"ethiopia", true},
    {"falkland islands (malvinas)", true},
    {"faroe islands", true},
    {"fiji", true},
    {"finland", true},
    {"france", true},
    {"french guiana", true},
    {"french polynesia", true},
    {"french southern territories", true},
    {"gabon", true},
    {"gambia", true},
    {"georgia", true},
    {"germany", true},
    {"ghana", true},
    {"gibraltar", true},
    {"greece", true},
    {"greenland", true},
    {"grenada", true},
    {"guadeloupe", true},
    {"guam", true},
    {"guatemala", true},
    {"guernsey", true},
    {"guinea", true},
    {"guinea-bissau", true},
    {"guyana", true},
    {"haiti", true},
    {"heard island and mcdonald islands", true},
    {"holy see", true},
    {"honduras", true},
    {"hong kong", true},
    {"hungary", true},
    {"iceland", true},
    {"india", true},
    {"indonesia", true},
    {"iran (islamic republic of)", true},
    {"iraq", true},
    {"ireland", true},
    {"isle of man", true},
    {"israel", true},
    {"italy", true},
    {"jamaica", true},
    {"japan", true},
    {"jersey", true},
    {"jordan", true},
    {"kazakhstan", true},
    {"kenya", true},
    {"kiribati", true},
    {"korea (democratic people's republic of)", true},
    {"korea (republic of)", true},
    {"kuwait", true},
    {"kyrgyzstan", true},
    {"lao people's democratic republic", true},
    {"latvia", true},
    {"lebanon", true},
    {"lesotho", true},
    {"liberia", true},
    {"libya", true},
    {"liechtenstein", true},
    {"lithuania", true},
    {"luxembourg", true},
    {"macao", true},
    {"macedonia (the former yugoslav republic of)", true},
    {"madagascar", true},
    {"malawi", true},
    {"malaysia", true},
    {"maldives", true},
    {"mali", true},
    {"malta", true},
    {"marshall islands", true},
    {"martinique", true},
    {"mauritania", true},
    {"mauritius", true},
    {"mayotte", true},
    {"mexico", true},
    {"micronesia (federated states of)", true},
    {"moldova (republic of)", true},
    {"monaco", true},
    {"mongolia", true},
    {"montenegro", true},
    {"montserrat", true},
    {"morocco", true},
    {"mozambique", true},
    {"myanmar", true},
    {"namibia", true},
    {"nauru", true},
    {"nepal", true},
    {"netherlands", true},
    {"new caledonia", true},
    {"new zealand", true},
    {"nicaragua", true},
    {"niger", true},
    {"nigeria", true},
    {"niue", true},
    {"norfolk island", true},
    {"northern mariana islands", true},
    {"norway", true},
    {"oman", true},
    {"pakistan", true},
    {"palau", true},
    {"palestine, state of", true},
    {"panama", true},
    {"papua new guinea", true},
    {"paraguay", true},
    {"peru", true},
    {"philippines", true},
    {"pitcairn", true},
    {"poland", true},
    {"portugal", true},
    {"puerto rico", true},
    {"qatar", true},
    {"réunion", true},
    {"romania", true},
    {"russian federation", true},
    {"rwanda", true},
    {"saint barthélemy", true},
    {"saint helena, ascension and tristan da cunha", true},
    {"saint kitts and nevis", true},
    {"saint lucia", true},
    {"saint martin (french part)", true},
    {"saint pierre and miquelon", true},
    {"saint vincent and the grenadines", true},
    {"samoa", true},
    {"san marino", true},
    {"sao tome and principe", true},
    {"saudi arabia", true},
    {"senegal", true},
    {"serbia", true},
    {"seychelles", true},
    {"sierra leone", true},
    {"singapore", true},
    {"sint maarten (dutch part)", true},
    {"slovakia", true},
    {"slovenia", true},
    {"solomon islands", true},
    {"somalia", true},
    {"south africa", true},
    {"south georgia and the south sandwich islands", true},
    {"south sudan", true},
    {"spain", true},
    {"sri lanka", true},
    {"sudan", true},
    {"suriname", true},
    {"svalbard and jan mayen", true},
    {"swaziland", true},
    {"sweden", true},
    {"switzerland", true},
    {"syrian arab republic", true},
    {"taiwan, province of china", true},
    {"tajikistan", true},
    {"tanzania, united republic of", true},
    {"thailand", true},
    {"timor-leste", true},
    {"togo", true},
    {"tokelau", true},
    {"tonga", true},
    {"trinidad and tobago", true},
    {"tunisia", true},
    {"turkey", true},
    {"turkmenistan", true},
    {"turks and caicos islands", true},
    {"tuvalu", true},
    {"uganda", true},
    {"ukraine", true},
    {"united arab emirates", true},
    {"united kingdom of great britain and northern ireland", true},
    {"united states of america", true},
    {"united states minor outlying islands", true},
    {"uruguay", true},
    {"uzbekistan", true},
    {"vanuatu", true},
    {"venezuela (bolivarian republic of)", true},
    {"viet nam", true},
    {"virgin islands (british)", true},
    {"virgin islands (u.s.)", true},
    {"wallis and futuna", true},
    {"western sahara", true},
    {"yemen", true},
    {"zambia", true},
    {"zimbabwe", true}
};
bool validate_Country(string country) {
    for (ll i = 0; i < country.size(); i++)country[i] = tolower(country[i]);
    return countryNames[country];
}