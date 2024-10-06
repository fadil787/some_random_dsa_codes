int main() {
    int hour, minute;
    float diff;

    // Take the hour and minute inputs
    cout << "Enter the hour (1-12): " << endl;
    cin >> hour;
    
    cout << "Enter the minute (0-59): " << endl;
    cin >> minute;

    // Normalize the hour to the range 1-12
    hour = hour % 12;  // Adjust for hours > 12

    // Calculate the angle of the hour hand (taking into account the minutes)
    float hour_angle = (hour * 30) + ((30.0 / 60.0) * minute);
    
    // Calculate the angle of the minute hand
    float min_angle = minute * 6;

    // Calculate the absolute difference between the two angles
    diff = abs(hour_angle - min_angle);

    // The actual difference should be the minimum of diff or 360 - diff
    diff = min(diff, 360 - diff);

    // Output the result
    cout << "The minimum angle between the hour and minute hands is: " << diff << " degrees." << endl;

    return 0;
}
