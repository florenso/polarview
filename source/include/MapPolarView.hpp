#ifndef _MAPPOLARVIEW_H
#define _MAPPOLARVIEW_H

#include "DistanceReading.hpp"
#include <map>
#include <algorithm>
#include <tuple>

class MapPolarView{
public:
    //Default constructor
    MapPolarView();

    //Collapses the PolarView into a PolarView that contains every datapoint only once
    // For instance: when the robot spins twice, the values will
    // overlap at the 360th degree.
    // Collapse will get rid of the duplucate values.
    // However: when for example the 16th degree
    // wasn't captured and the 376th is available,
    // it will use that value instead.
    // virtual ArrayPolarView collapse() = 0;

    //Rotates the PolarView with a given angle.
    void rotate(int angle);

    //Matches the PolarView with a given PolarView
    //Returns a value that is a perentage that indicates how much
    //the PolarViews are alike.
    double match(MapPolarView v);

    //Finds the best match with the given PolarView.
    //Returns the rotation and the multiplication factor
    //that best matches in a std::tuple
    std::tuple<int, double> find_best_match(MapPolarView v);

    //Returns all the distance readings in the polarview
    std::map<int, DistanceReading> & get_distances();

    //Multiplies the distances with a given multiplier
    MapPolarView scale(double frac);

    //Adds 2 ArrayPolarviews together. This does not add
    //two values together but rather 'merges' the two PolarViews
    MapPolarView operator+=(MapPolarView v);
    MapPolarView operator+(MapPolarView v);

    void add_distancereading(int angle, Length len, DistanceReading::ResultType type);
    void add_distancereading(int angle, DistanceReading dist);

private:
    std::map <int, DistanceReading> readings;

};

#endif //_MAPPOLARVIEW_H
