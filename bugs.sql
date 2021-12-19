-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3306
-- Generation Time: Dec 19, 2021 at 03:56 PM
-- Server version: 5.7.31
-- PHP Version: 7.3.21

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `bugs`
--

-- --------------------------------------------------------

--
-- Table structure for table `bugs`
--

DROP TABLE IF EXISTS `bugs`;
CREATE TABLE IF NOT EXISTS `bugs` (
  `bug_id` mediumint(9) NOT NULL AUTO_INCREMENT,
  `assigned_to` mediumint(9) NOT NULL,
  `bug_file_loc` mediumtext NOT NULL,
  `bug_severity` varchar(64) NOT NULL,
  `bug_status` varchar(64) NOT NULL,
  `creation_ts` datetime DEFAULT NULL,
  `delta_ts` datetime NOT NULL,
  `short_desc` varchar(255) NOT NULL,
  `op_sys` varchar(64) NOT NULL,
  `priority` varchar(64) NOT NULL,
  `product_id` smallint(6) NOT NULL,
  `rep_platform` varchar(64) NOT NULL,
  `reporter` mediumint(9) NOT NULL,
  `version` varchar(64) NOT NULL,
  `component_id` mediumint(9) NOT NULL,
  `resolution` varchar(64) NOT NULL DEFAULT '',
  `target_milestone` varchar(64) NOT NULL DEFAULT '---',
  `qa_contact` mediumint(9) DEFAULT NULL,
  `status_whiteboard` mediumtext NOT NULL,
  `lastdiffed` datetime DEFAULT NULL,
  `everconfirmed` tinyint(4) NOT NULL,
  `reporter_accessible` tinyint(4) NOT NULL DEFAULT '1',
  `cclist_accessible` tinyint(4) NOT NULL DEFAULT '1',
  `estimated_time` decimal(7,2) NOT NULL DEFAULT '0.00',
  `remaining_time` decimal(7,2) NOT NULL DEFAULT '0.00',
  `deadline` datetime DEFAULT NULL,
  PRIMARY KEY (`bug_id`),
  KEY `bugs_assigned_to_idx` (`assigned_to`),
  KEY `bugs_creation_ts_idx` (`creation_ts`),
  KEY `bugs_delta_ts_idx` (`delta_ts`),
  KEY `bugs_bug_severity_idx` (`bug_severity`),
  KEY `bugs_bug_status_idx` (`bug_status`),
  KEY `bugs_op_sys_idx` (`op_sys`),
  KEY `bugs_priority_idx` (`priority`),
  KEY `bugs_product_id_idx` (`product_id`),
  KEY `bugs_reporter_idx` (`reporter`),
  KEY `bugs_version_idx` (`version`),
  KEY `bugs_component_id_idx` (`component_id`),
  KEY `bugs_resolution_idx` (`resolution`),
  KEY `bugs_target_milestone_idx` (`target_milestone`),
  KEY `bugs_qa_contact_idx` (`qa_contact`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `bugs`
--

INSERT INTO `bugs` (`bug_id`, `assigned_to`, `bug_file_loc`, `bug_severity`, `bug_status`, `creation_ts`, `delta_ts`, `short_desc`, `op_sys`, `priority`, `product_id`, `rep_platform`, `reporter`, `version`, `component_id`, `resolution`, `target_milestone`, `qa_contact`, `status_whiteboard`, `lastdiffed`, `everconfirmed`, `reporter_accessible`, `cclist_accessible`, `estimated_time`, `remaining_time`, `deadline`) VALUES
(4, 5, '', 'enhancement', 'RESOLVED', '2021-12-17 16:12:18', '2021-12-17 16:19:17', 'Khi nhập số lượng nv ,doanh so,nam thanh lap thì hệ thống cho nhập số âm', 'Windows', '---', 3, 'PC', 1, 'unspecified', 8, 'FIXED', '---', NULL, '', '2021-12-17 16:19:17', 1, 1, 1, '0.00', '0.00', NULL),
(5, 1, '', 'enhancement', 'RESOLVED', '2021-12-17 16:40:04', '2021-12-17 16:49:49', 'Hàm kiểm tra min trong hàm inMaxMinDoanhSo không được gán cứng 9999 vì số bé nhất có thể là 10000', 'Windows', '---', 3, 'PC', 5, 'unspecified', 8, 'FIXED', '---', NULL, '', '2021-12-17 16:49:50', 1, 1, 1, '0.00', '0.00', NULL),
(6, 1, '', 'enhancement', 'RESOLVED', '2021-12-17 16:56:56', '2021-12-17 17:03:16', 'Hàm kiểm tra min trong hàm inMaxMinNhanVien không được gán cứng 9999 vì số bé nhất có thể là 10000', 'Windows', '---', 3, 'PC', 5, 'unspecified', 8, 'FIXED', '---', NULL, '', '2021-12-17 17:03:16', 1, 1, 1, '0.00', '0.00', NULL),
(7, 5, '', 'enhancement', 'RESOLVED', '2021-12-17 17:10:51', '2021-12-17 17:16:22', 'Lỗi lương cơ bản có thể nhập được số âm', 'Windows', '---', 3, 'PC', 1, 'unspecified', 8, 'FIXED', '---', NULL, '', '2021-12-17 17:16:23', 1, 1, 1, '0.00', '0.00', NULL),
(8, 1, '', 'enhancement', 'RESOLVED', '2021-12-18 13:44:46', '2021-12-18 13:50:16', 'Không được gán cứng năm là 2021', 'Windows', '---', 3, 'PC', 5, 'unspecified', 8, 'FIXED', '---', NULL, '', '2021-12-18 13:50:16', 1, 1, 1, '0.00', '0.00', NULL),
(10, 5, '', 'enhancement', 'RESOLVED', '2021-12-18 17:09:22', '2021-12-18 17:11:00', 'Số lợi nhuận nhập vào có số âm', 'Windows', '---', 3, 'PC', 1, 'unspecified', 8, 'FIXED', '---', NULL, '', '2021-12-18 17:11:00', 1, 1, 1, '0.00', '0.00', NULL);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `bugs`
--
ALTER TABLE `bugs`
  ADD CONSTRAINT `fk_bugs_assigned_to_profiles_userid` FOREIGN KEY (`assigned_to`) REFERENCES `profiles` (`userid`) ON UPDATE CASCADE,
  ADD CONSTRAINT `fk_bugs_component_id_components_id` FOREIGN KEY (`component_id`) REFERENCES `components` (`id`) ON UPDATE CASCADE,
  ADD CONSTRAINT `fk_bugs_product_id_products_id` FOREIGN KEY (`product_id`) REFERENCES `products` (`id`) ON UPDATE CASCADE,
  ADD CONSTRAINT `fk_bugs_qa_contact_profiles_userid` FOREIGN KEY (`qa_contact`) REFERENCES `profiles` (`userid`) ON UPDATE CASCADE,
  ADD CONSTRAINT `fk_bugs_reporter_profiles_userid` FOREIGN KEY (`reporter`) REFERENCES `profiles` (`userid`) ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
