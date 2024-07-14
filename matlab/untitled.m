close all
clear all
clc

%%
kitt_data_dir = '/Users/adamclare/data/2011_09_30/2011_09_30_drive_0016_sync';

%% Load lidar points
bin_files = dir(sprintf('%s/%s', kitt_data_dir, 'velodyne_points/data'));
% We minus 2 on the length of bin_files because dir() will return '.', and
% '..' as directories
fprintf('Found %d number of velodnye scans\n\n', length(bin_files) - 2);

player = pcplayer([-100 100], [-100, 100], [-10, 10]);
for i=3:length(bin_files)
    
    fid = fopen(sprintf('%s/velodyne_points/data/%s', kitt_data_dir, bin_files(i).name), 'rb');
    data = fread(fid, 'float32');
    fclose(fid);
    data = reshape(data, 4, [])';
    
    scan_rings = PointCloudToScanRings(data);
%     view(player, data(:, 1:3));
end