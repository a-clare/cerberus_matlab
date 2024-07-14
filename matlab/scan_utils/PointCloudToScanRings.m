function [scanRings] = PointCloudToScanRings(ptCloud)
% Convert a point cloud of N points into individual scan rings based on the
% lidar sensor configuration

scanRings = cell(64, 1);

num_points = length(ptCloud);

for i = 1:num_points
    point = ptCloud(i, :);
    
    point2 = point.^2;
    vertical_angle = atan(point(3) / sqrt(point2(1) + point2(2))) * 180 / pi;

    scan_id = 0;
    % TODO: Test vertical angle of point against lidar sensor configuration

    % The HDL64 separates the 64 lasers into an upper block and lower block, each block has 32 lasers.
    % It has a total vertical resolution of +2 degrees to -24.8 degrees.
    % However, each block has a different vertical angle separation.
    % The upper block, from [-8.33 to +2] has a 1/3 degree separation
    % The lower block, from [-24.33 to -8.33 has a 1/2 degree separation
    % AKA its not uniform (each ring is not equally spaced), so in order to separate the point cloud 
    % into scan rings we need to check if we are in the upper or lower block first
    if vertical_angle >= -8.83
        scan_id = round((2.0 - vertical_angle) * 3.0 + 0.5);
    else
        scan_id = 32 + round((-8.83 - vertical_angle) * 2.0 + 0.5);
    end
    
    scan_id
    scanRings{scan_id + 1}(end + 1, :) = point;
end

end

