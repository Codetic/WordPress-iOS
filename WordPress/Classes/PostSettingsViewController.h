#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <MapKit/MapKit.h>
#import "UITableViewActivityCell.h"
#import "EditPostViewController.h"
#import "CPopoverManager.h"
#import "PostAnnotation.h"
#import "UIImageView+AFNetworking.h"

// the amount of vertical shift upwards keep the text field in view as the keyboard appears
#define kOFFSET_FOR_KEYBOARD                    150.0

@class EditPostViewController;
@interface PostSettingsViewController : UIViewController <UITableViewDelegate, UITableViewDataSource, UIPickerViewDelegate, UIPickerViewDataSource, UITextFieldDelegate, CLLocationManagerDelegate, UIActionSheetDelegate> {
    IBOutlet UITableView *tableView;
    IBOutlet UITableViewCell *visibilityTableViewCell;
    UILabel *statusLabel;
    IBOutlet UILabel *visibilityLabel;
    IBOutlet UILabel *postFormatLabel;
    IBOutlet UITextField *passwordTextField;
    UILabel *publishOnDateLabel;
    UITextField *tagsTextField;
    EditPostViewController *__weak postDetailViewController;
    NSArray *statusList;
    NSArray *visibilityList;
    NSArray *formatsList;
    UIPickerView *pickerView;
    UIActionSheet *actionSheet;
    UIDatePicker *datePickerView;
    UIPopoverController *popover;
    BOOL isShowingKeyboard, blogSupportsFeaturedImage;

	/* Geotagging */
	CLLocationManager *locationManager;
    CLGeocoder *reverseGeocoder;
    UITableViewActivityCell *addGeotagTableViewCell;
    IBOutlet UITableViewCell *mapGeotagTableViewCell;
	UITableViewCell *removeGeotagTableViewCell;
	IBOutlet MKMapView *mapView;
	IBOutlet UILabel *addressLabel;
	IBOutlet UILabel *coordinateLabel;
	PostAnnotation *annotation;
	NSString *address;
	BOOL isUpdatingLocation, isUploadingFeaturedImage;
    IBOutlet UILabel *visibilityTitleLabel, *featuredImageLabel;
    IBOutlet UIImageView *featuredImageView;
    IBOutlet UITableViewCell *featuredImageTableViewCell;
    IBOutlet UIActivityIndicatorView *featuredImageSpinner;
}

@property (nonatomic, strong) NSString *statsPrefix;
@property (nonatomic, weak) EditPostViewController *postDetailViewController;
@property (nonatomic, strong) IBOutlet UITableViewCell *postFormatTableViewCell;

- (id)initWithPost:(AbstractPost *)aPost;

- (void)reloadData;
- (void)endEditingAction:(id)sender;
- (void)featuredImageUploadFailed: (NSNotification *)notificationInfo;
- (void)featuredImageUploadSucceeded: (NSNotification *)notificationInfo;
- (void)showFeaturedImageUploader: (NSNotification *)notificationInfo;
@end
