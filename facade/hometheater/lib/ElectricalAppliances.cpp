#include <iostream>
#include <string>
#include <memory>
#include "include/ElectricalAppliances.h"

void CDPlayer::powerOn() {
    std::cout << "CDPlayer power on" << std::endl;
}

void CDPlayer::poweroff() {
    std::cout << "CDPlayer power off" << std::endl;
}

void CDPlayer::eject() {
    std::cout << "CDPlayer eject CD" << std::endl;
}

void CDPlayer::play(std::string title) {
    std::cout << "CDPlayer play : " << title << std::endl;
    _title = title;
}

void CDPlayer::play(int track) {
    std::cout << "CDPlayer play : " << track << std::endl;
    _currentTrack = track;
}

void CDPlayer::stop() {
    std::cout << "CDPlayer stop playing" << std::endl;
}

void CDPlayer::pause() {
    std::cout << "CDPlayer pause" << std::endl;
}

std::string CDPlayer::toString() {
    return "CDPlayer";
}

void DvdPlayer::powerOn() {
    std::cout << "DvdPlayer power on" << std::endl;
}

void DvdPlayer::poweroff() {
    std::cout << "DvdPlayer power off" << std::endl;
}

void DvdPlayer::eject() {
    std::cout << "DvdPlayer eject DVD" << std::endl;
}

void DvdPlayer::play(std::string movie) {
    std::cout << "DvdPlayer play : " << movie << std::endl;
    _movie = movie;
}

void DvdPlayer::play(int track) {
    std::cout << "DvdPlayer play : " << track << std::endl;
    _currentTrack = track;
}

void DvdPlayer::stop() {
    std::cout << "DvdPlayer stop playing" << std::endl;
}

void DvdPlayer::pause() {
    std::cout << "DvdPlayer pause" << std::endl;
}

void DvdPlayer::setTwoChannelAudio() {
    std::cout << "DvdPlayer setTwoChannelAudio" << std::endl;
}

void DvdPlayer::setSurroundAudio() {
    std::cout << "DvdPlayer setSurroundAudio" << std::endl;
}

std::string DvdPlayer::toString() {
    return "DvdPlayer";
}

void Tuner::powerOn() {
    std::cout << "Tuner power on" << std::endl;
}

void Tuner::poweroff() {
    std::cout << "Tuner power off" << std::endl;
}

void Tuner::setFrequency(double frequency) {
    std::cout << "Tuner setFrequency : " << frequency << std::endl;
    _frequency = frequency;
}

void Tuner::setAM() {
    std::cout << "Tuner setAM" << std::endl;
}

void Tuner::setFM() {
    std::cout << "Tuner setFM" << std::endl;
}

std::string Tuner::toString() {
    return "Tuner";
}

void PopcornPopper::powerOn() {
    std::cout << "PopcornPopper power on" << std::endl;
}

void PopcornPopper::poweroff() {
    std::cout << "PopcornPopper power off" << std::endl;
}

void PopcornPopper::popcorn() {
    std::cout << "PopcornPopper popcorn" << std::endl;
}

std::string PopcornPopper::toString() {
    return "PopcornPopper";
}

void Projector::powerOn() {
    std::cout << "Projector power on" << std::endl;
}

void Projector::poweroff() {
    std::cout << "Projector power off" << std::endl;
}

void Projector::wideScreenMode() {
    std::cout << "Projector wideScreenMode" << std::endl;
}

void Projector::tvMode() {
    std::cout << "Projector tvMode" << std::endl;
}

std::string Projector::toString() {
    return "Projector";
}

void Screen::up() {
    std::cout << "Screen up" << std::endl;
}

void Screen::down() {
    std::cout << "Screen down" << std::endl;
}

std::string Screen::toString() {
    return "Screen";
}

void TheaterLights::powerOn() {
    std::cout << "TheaterLights power on" << std::endl;
}

void TheaterLights::poweroff() {
    std::cout << "TheaterLights power off" << std::endl;
}

void TheaterLights::dim(int dim) {
    std::cout << "TheaterLights dim : " << dim << std::endl;
}

std::string TheaterLights::toString() {
    return "TheaterLights";
}

void Amplifier::powerOn() {
    std::cout << "Amplifier power on" << std::endl;
}

void Amplifier::poweroff() {
    std::cout << "Amplifier power off" << std::endl;
}

void Amplifier::setStereoSound() {
    std::cout << "Amplifier setStereoSound" << std::endl;
}

void Amplifier::setSurroundSound() {
    std::cout << "Amplifier setSurroundAudio" << std::endl;
}

void Amplifier::setVolume(int vol) {
    std::cout << "Amplifier setVolume : " << vol << std::endl;
}

void Amplifier::setTuner(Tuner* tuner) {
    std::cout << "Amplifier setTuner : " << tuner->toString() << std::endl;
}

void Amplifier::setDvd(DvdPlayer* dvd) {
    std::cout << "Amplifier setDvd : " << dvd->toString() << std::endl;
}

void Amplifier::setCD(CDPlayer* cd) {
    std::cout << "Amplifier setCD : " << cd->toString() << std::endl;
}

std::string Amplifier::toString() {
    return "Amplifier";
}
